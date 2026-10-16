#!/usr/bin/env python3
"""Publie une image de test RGB-D et affiche les pieces renvoyees par la perception."""

import csv
import json
import math
from pathlib import Path
import time

import cv2
import numpy as np
import rclpy
from cv_bridge import CvBridge
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import CameraInfo, Image
import yaml

from tower_interfaces.msg import PieceArray
from tower_interfaces.srv import AnalyzeImage


def make_example(catalog, fx, fy, cx, cy, table_depth):
    """Vue du dessus : trois pieces connues posees sur un meme support virtuel."""
    bgr = np.full((640, 960, 3), 25, dtype=np.uint8)
    depth = np.full((640, 960), table_depth, dtype=np.float32)
    for x in range(0, 960, 40):
        cv2.line(bgr, (x, 0), (x, 639), (40, 40, 40), 1)
    for y in range(0, 640, 40):
        cv2.line(bgr, (0, y), (959, y), (40, 40, 40), 1)
    items = [
        ('cube', 'red', (240, 230), 15.0, (0, 0, 255),
         catalog['cube_side_m'], catalog['cube_side_m'], catalog['cube_side_m']),
        ('rectangle', 'blue', (520, 260), -20.0, (255, 0, 0),
         catalog['rectangle_length_m'], catalog['rectangle_width_m'],
         catalog['rectangle_height_m']),
        ('cylindre', 'green', (750, 430), 0.0, (0, 255, 0),
         catalog['cylinder_diameter_m'], catalog['cylinder_diameter_m'],
         catalog['cylinder_height_m']),
    ]
    expected = []
    for shape, color, (u, v), angle, bgr_color, length, width, height in items:
        surface_z = table_depth - height
        if surface_z <= 0.1:
            raise ValueError('La distance de table doit depasser la hauteur des pieces de 0.1 m.')
        mask = np.zeros(bgr.shape[:2], dtype=np.uint8)
        if shape == 'cylindre':
            axes = (max(2, round(fx * length / (2 * surface_z))),
                    max(2, round(fy * width / (2 * surface_z))))
            cv2.ellipse(mask, (u, v), axes, 0, 0, 360, 255, -1)
        else:
            corners = cv2.boxPoints(((u, v), (fx * length / surface_z,
                                             fy * width / surface_z), angle))
            cv2.fillConvexPoly(mask, np.rint(corners).astype(np.int32), 255)
        bgr[mask > 0] = bgr_color
        depth[mask > 0] = surface_z
        cv2.putText(bgr, shape, (u - 50, v + 80), cv2.FONT_HERSHEY_SIMPLEX,
                    0.6, (220, 220, 220), 1)
        expected.append({
            'color': color, 'center_px': [u, v],
            'center_m': [(u - cx) * surface_z / fx,
                         (v - cy) * surface_z / fy, table_depth - height / 2],
            'dimensions_m': [length, width, height],
        })
    cv2.putText(bgr, 'SIMULATION - vue du dessus', (20, 35),
                cv2.FONT_HERSHEY_SIMPLEX, 0.7, (220, 220, 220), 1)
    return bgr, depth, expected


class ImageSimulator(Node):
    def __init__(self):
        super().__init__('image_simulator')
        self.finished = False
        self.exit_code = 0
        self.bridge = CvBridge()
        self.frame = 'simulation_color_optical_frame'
        self.once = self.declare_parameter('once', False).value
        self.auto_analyze = self.declare_parameter('auto_analyze', True).value
        self.wait_for_controller = self.declare_parameter('wait_for_controller', True).value
        self.output_dir = Path(self.declare_parameter('output_dir', 'simulation_output').value).expanduser().resolve()
        image_path = self.declare_parameter('image_path', '').value
        config_path = self.declare_parameter('config_path', '').value
        with open(config_path, encoding='utf-8') as stream:
            config = yaml.safe_load(stream)['perception_node']['ros__parameters']
        keys = ('cube_side_m', 'rectangle_length_m', 'rectangle_width_m',
                'rectangle_height_m', 'cylinder_diameter_m', 'cylinder_height_m')
        catalog = {key: float(config[key]) for key in keys}
        if not all(math.isfinite(value) and value > 0 for value in catalog.values()):
            raise ValueError('Les dimensions du catalogue doivent etre finies et positives.')
        self.fx = float(self.declare_parameter('fx', 800.0).value)
        self.fy = float(self.declare_parameter('fy', 800.0).value)
        self.cx = float(self.declare_parameter('cx', -1.0).value)
        self.cy = float(self.declare_parameter('cy', -1.0).value)
        distance = float(self.declare_parameter('depth_m', 0.8).value)
        if not all(math.isfinite(value) and value > 0 for value in (self.fx, self.fy, distance)):
            raise ValueError('fx, fy et depth_m doivent etre finis et positifs.')
        if not all(math.isfinite(value) for value in (self.cx, self.cy)):
            raise ValueError('cx et cy doivent etre finis.')

        expected = []
        if image_path:
            path = Path(image_path).expanduser().resolve()
            self.bgr = cv2.imread(str(path), cv2.IMREAD_COLOR)
            if self.bgr is None:
                raise ValueError(f'Image illisible : {path}')
            self.depth = np.full(self.bgr.shape[:2], distance, dtype=np.float32)
            mode = 'image fournie, profondeur de face et calibration SIMULEES'
        else:
            # La scene generee utilise le plan de support a depth_m.
            mode = 'scene et camera SIMULEES'
            if self.cx < 0:
                self.cx = 480.0
            if self.cy < 0:
                self.cy = 320.0
            self.bgr, self.depth, expected = make_example(
                catalog, self.fx, self.fy, self.cx, self.cy, distance)
        height, width = self.bgr.shape[:2]
        if self.cx < 0:
            self.cx = width / 2.0
        if self.cy < 0:
            self.cy = height / 2.0

        self.info = CameraInfo()
        self.info.width, self.info.height = width, height
        self.info.header.frame_id = self.frame
        self.info.distortion_model = 'plumb_bob'
        self.info.d = [0.0] * 5
        self.info.k = [self.fx, 0., self.cx, 0., self.fy, self.cy, 0., 0., 1.]
        self.info.r = [1., 0., 0., 0., 1., 0., 0., 0., 1.]
        self.info.p = [self.fx, 0., self.cx, 0., 0., self.fy, self.cy, 0., 0., 0., 1., 0.]
        self.color_message = self.bridge.cv2_to_imgmsg(self.bgr, encoding='bgr8')
        self.depth_message = self.bridge.cv2_to_imgmsg(self.depth, encoding='32FC1')
        self.color_message.header.frame_id = self.frame
        self.depth_message.header.frame_id = self.frame
        self.output_dir.mkdir(parents=True, exist_ok=True)
        self.write_image('scene.png', self.bgr)
        np.save(self.output_dir / 'depth.npy', self.depth)
        self.metadata = {
            'mode': mode, 'coordinates_are_simulated': True, 'frame_id': self.frame,
            'image_path': image_path, 'fx': self.fx, 'fy': self.fy,
            'cx': self.cx, 'cy': self.cy, 'depth_m': distance,
            'catalog_m': catalog, 'expected_pieces': expected,
        }
        self.write_json('scene.json', self.metadata)

        self.color_pub = self.create_publisher(Image, '/simulation/color', qos_profile_sensor_data)
        self.depth_pub = self.create_publisher(Image, '/simulation/depth', qos_profile_sensor_data)
        self.info_pub = self.create_publisher(CameraInfo, '/simulation/camera_info', qos_profile_sensor_data)
        self.client = self.create_client(AnalyzeImage, '/simulation/perception/analyze_image')
        self.pieces_sub = self.create_subscription(
            PieceArray, '/simulation/detected_pieces', self.on_pieces, 10)
        self.debug_sub = self.create_subscription(
            Image, '/simulation/perception/debug_image', self.on_debug, 10)
        self.published = 0
        self.future = None
        self.analysis_done = False
        self.received_result = False
        self.received_debug = False
        self.result_time = None
        self.started = time.monotonic()
        self.timer = self.create_timer(0.1, self.tick)
        self.get_logger().info(f'Mode : {mode}. Les XYZ ne sont pas des mesures reelles.')
        self.get_logger().info(f'Image et resultats : {self.output_dir}')

    def write_json(self, name, value):
        (self.output_dir / name).write_text(
            json.dumps(value, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')

    def write_image(self, name, value):
        if not cv2.imwrite(str(self.output_dir / name), value):
            raise OSError(f'Impossible de sauvegarder {self.output_dir / name}')

    def receivers_ready(self):
        if not all(publisher.get_subscription_count() > 0 for publisher in
                   (self.color_pub, self.depth_pub, self.info_pub)):
            return False
        # La liste est publiee une seule fois : attendre l'abonne avant de la demander.
        return not self.wait_for_controller or any(
            endpoint.node_name == 'tower_controller' and endpoint.node_namespace == '/simulation'
            for endpoint in self.get_subscriptions_info_by_topic('/simulation/detected_pieces'))

    def tick(self):
        stamp = self.get_clock().now().to_msg()
        self.info.header.stamp = stamp
        self.color_message.header.stamp = stamp
        self.depth_message.header.stamp = stamp
        self.info_pub.publish(self.info)
        self.color_pub.publish(self.color_message)
        self.depth_pub.publish(self.depth_message)
        self.published += 1

        if (self.auto_analyze and not self.analysis_done and self.future is None
                and self.published >= 5 and self.client.service_is_ready()
                and self.receivers_ready()):
            self.future = self.client.call_async(AnalyzeImage.Request())
            self.future.add_done_callback(self.on_response)
        if self.once and self.received_result and self.received_debug:
            # Laisser le temps au controleur d'afficher le meme vecteur.
            if time.monotonic() - self.result_time > 0.5:
                self.finished = True
        elif self.auto_analyze and not self.analysis_done and time.monotonic() - self.started > 20:
            self.get_logger().error('Analyse indisponible apres 20 s ; verifier les logs de perception.')
            self.exit_code = 1
            self.finished = True

    def on_response(self, future):
        self.future = None
        try:
            response = future.result()
            if response.success:
                self.analysis_done = True
            else:
                self.get_logger().warning(response.message)
        except Exception as error:
            self.get_logger().error(str(error))
            self.exit_code = 1
            self.finished = True

    def on_pieces(self, observation):
        if observation.header.frame_id != self.frame:
            self.get_logger().error('Repere inattendu dans la simulation.')
            self.exit_code = 1
            self.finished = True
            return
        rows = []
        self.get_logger().info('Centres : pixels (u,v) et XYZ SIMULES en metres')
        self.get_logger().info(' id  couleur      u(px)    v(px)      X(m)      Y(m)      Z(m)')
        for piece in observation.pieces:
            center = piece.pose.pose.position
            dimensions = piece.dimensions
            # Le nœud renvoie le centre du volume : retrouver le dessus pour les pixels.
            top_z = center.z - dimensions.z / 2.0
            u = self.fx * center.x / top_z + self.cx
            v = self.fy * center.y / top_z + self.cy
            row = {
                'id': piece.id, 'color': piece.color, 'center_px': [u, v],
                'center_m': [center.x, center.y, center.z],
                'dimensions_m': [dimensions.x, dimensions.y, dimensions.z],
                'confidence': float(piece.confidence),
            }
            rows.append(row)
            self.get_logger().info(
                f'{piece.id:3}  {piece.color:8} {u:8.1f} {v:8.1f}'
                f' {center.x:9.4f} {center.y:9.4f} {center.z:9.4f}')
        if not rows:
            self.get_logger().info('Aucune piece detectee.')
        self.write_json('pieces.json', {
            'coordinates_are_simulated': True, 'frame_id': observation.header.frame_id,
            'stamp': {'sec': observation.header.stamp.sec, 'nanosec': observation.header.stamp.nanosec},
            'pieces': rows,
        })
        with (self.output_dir / 'pieces.csv').open('w', newline='', encoding='utf-8') as stream:
            writer = csv.writer(stream)
            writer.writerow(['id', 'color', 'u_px', 'v_px', 'x_sim_m', 'y_sim_m', 'z_sim_m'])
            for row in rows:
                writer.writerow([row['id'], row['color'], *row['center_px'], *row['center_m']])
        self.received_result = True
        self.result_time = time.monotonic()
        self.get_logger().info(f'Resultats sauvegardes dans {self.output_dir / "pieces.json"}')

    def on_debug(self, message):
        self.write_image('annotated.png', self.bridge.imgmsg_to_cv2(message, desired_encoding='bgr8'))
        self.received_debug = True


def main(args=None):
    rclpy.init(args=args)
    node = None
    exit_code = 0
    try:
        node = ImageSimulator()
        while rclpy.ok() and not node.finished:
            rclpy.spin_once(node, timeout_sec=0.1)
        exit_code = node.exit_code
    except KeyboardInterrupt:
        pass
    except Exception as error:
        rclpy.logging.get_logger('image_simulator').error(str(error))
        exit_code = 1
    finally:
        if node is not None:
            node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
    return exit_code


if __name__ == '__main__':
    raise SystemExit(main())
