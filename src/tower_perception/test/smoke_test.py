"""Test ROS de bout en bout sur images synthetiques, sans camera ni robot."""

import os
import random
import signal
import subprocess
import tempfile
import time
from pathlib import Path

import cv2
import numpy as np
import rclpy
from ament_index_python.packages import get_package_prefix
from geometry_msgs.msg import TransformStamped
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import CameraInfo, Image
from std_msgs.msg import Empty
from tf2_ros import StaticTransformBroadcaster
from tower_interfaces.msg import PieceArray
from tower_interfaces.srv import AnalyzeImage


def main():
    # Isoler les images et demandes de test des autres participants du reseau.
    os.environ['ROS_DOMAIN_ID'] = str(random.SystemRandom().randint(120, 160))
    os.environ['ROS_LOCALHOST_ONLY'] = '1'
    processes = []
    rclpy.init()
    node = Node('perception_smoke_test')
    observations = []
    debug_images = []
    subscriptions = [
        node.create_subscription(PieceArray, '/detected_pieces', observations.append, 10),
        node.create_subscription(Image, '/perception/debug_image', debug_images.append, 10),
    ]
    color_pub = node.create_publisher(Image, '/test/color', qos_profile_sensor_data)
    depth_pub = node.create_publisher(Image, '/test/depth', qos_profile_sensor_data)
    info_pub = node.create_publisher(CameraInfo, '/test/info', qos_profile_sensor_data)
    trigger_pub = node.create_publisher(Empty, '/perception/analyze', 10)
    client = node.create_client(AnalyzeImage, '/perception/analyze_image')
    broadcaster = StaticTransformBroadcaster(node)

    def spin_for(seconds):
        deadline = time.monotonic() + seconds
        while time.monotonic() < deadline:
            rclpy.spin_once(node, timeout_sec=0.02)

    def wait_for(predicate, seconds=5.0):
        deadline = time.monotonic() + seconds
        while not predicate():
            if time.monotonic() >= deadline:
                raise AssertionError('Delai depasse en attendant un evenement ROS.')
            rclpy.spin_once(node, timeout_sec=0.02)

    def request():
        future = client.call_async(AnalyzeImage.Request())
        wait_for(future.done)
        return future.result()

    def publish_scene(blank=False, invalid_depth=False):
        bgr = np.zeros((480, 640, 3), dtype=np.uint8)
        if not blank:
            cv2.rectangle(bgr, (60, 60), (99, 99), (0, 0, 255), -1)
            cv2.rectangle(bgr, (160, 60), (199, 99), (0, 0, 255), -1)
            cv2.rectangle(bgr, (260, 180), (339, 219), (255, 0, 0), -1)
            cv2.circle(bgr, (460, 300), 30, (0, 255, 0), -1)
        depth = np.full((480, 640), 0 if invalid_depth else 1000, dtype=np.uint16)
        info = CameraInfo()
        info.header.frame_id = 'test_camera_optical'
        info.width, info.height = 640, 480
        info.distortion_model = 'plumb_bob'
        info.d = [0.0] * 5
        info.k = [500., 0., 320., 0., 500., 240., 0., 0., 1.]
        info.r = [1., 0., 0., 0., 1., 0., 0., 0., 1.]
        info.p = [500., 0., 320., 0., 0., 500., 240., 0., 0., 0., 1., 0.]
        for _ in range(8):
            info.header.stamp = node.get_clock().now().to_msg()
            info_pub.publish(info)
            for publisher, array, encoding in [
                (color_pub, bgr, 'bgr8'), (depth_pub, depth, '16UC1')
            ]:
                image = Image()
                image.header = info.header
                image.height, image.width = array.shape[:2]
                image.encoding = encoding
                image.step = array.strides[0]
                image.data = array.tobytes()
                publisher.publish(image)
            spin_for(0.07)

    with tempfile.TemporaryDirectory(prefix='tower_perception_smoke_') as temp_dir:
        log_files = []
        try:
            for package, executable, extra in [
                ('tower_perception', 'perception_node', [
                    '--ros-args', '-p', 'color_topic:=/test/color',
                    '-p', 'depth_topic:=/test/depth', '-p', 'camera_info_topic:=/test/info',
                    '-p', 'rectangle_height_m:=0.02', '-p', 'cylinder_height_m:=0.05',
                    '-p', 'output_frame:=test_world', '-p', 'max_snapshot_age_s:=0.5']),
                ('tower_control', 'tower_controller', []),
            ]:
                log = open(Path(temp_dir) / (package + '.log'), 'w+')
                log_files.append(log)
                binary = Path(get_package_prefix(package)) / 'lib' / package / executable
                processes.append(subprocess.Popen(
                    [str(binary), *extra], stdout=log, stderr=subprocess.STDOUT,
                    start_new_session=True))
            assert client.wait_for_service(timeout_sec=15.0), 'Service non disponible.'
            wait_for(lambda: color_pub.get_subscription_count() > 0 and
                     depth_pub.get_subscription_count() > 0 and
                     info_pub.get_subscription_count() > 0 and
                     trigger_pub.get_subscription_count() > 0)
            assert not request().success, 'Une analyse sans images doit echouer.'
            assert not observations

            publish_scene()
            assert not observations, 'La camera seule ne doit pas declencher une analyse.'
            missing_tf = request()
            assert not missing_tf.success, 'La TF demandee manque : analyse attendue en echec.'
            assert not observations

            transform = TransformStamped()
            transform.header.stamp = node.get_clock().now().to_msg()
            transform.header.frame_id = 'test_world'
            transform.child_frame_id = 'test_camera_optical'
            transform.transform.translation.x = 0.1
            transform.transform.translation.y = 0.2
            transform.transform.translation.z = 0.3
            transform.transform.rotation.w = 1.0
            broadcaster.sendTransform(transform)
            spin_for(0.2)
            publish_scene()
            response = request()
            assert response.success, response.message
            assert len(response.observation.pieces) == 4
            assert [p.color for p in response.observation.pieces] == ['red', 'red', 'blue', 'green']
            assert response.observation.header.frame_id == 'test_world'
            assert all(p.pose.header == response.observation.header for p in response.observation.pieces)
            assert abs(response.observation.pieces[2].pose.pose.position.z - 1.31) < 1e-5
            wait_for(lambda: len(observations) >= 1 and len(debug_images) >= 1)
            assert observations[-1] == response.observation
            assert debug_images[-1].header.frame_id == 'test_camera_optical'
            ids = [p.id for p in response.observation.pieces]
            assert len(set(ids)) == 4

            publish_scene()
            assert [p.id for p in request().observation.pieces] == ids
            spin_for(0.1)
            before = len(observations)
            trigger_pub.publish(Empty())
            wait_for(lambda: len(observations) == before + 1)
            assert [p.id for p in observations[-1].pieces] == ids

            spin_for(0.65)
            before = len(observations)
            assert not request().success, 'Images perimees : analyse attendue en echec.'
            spin_for(0.1)
            assert len(observations) == before
            publish_scene(invalid_depth=True)
            assert not request().success, 'Profondeur nulle : analyse attendue en echec.'
            spin_for(0.1)
            assert len(observations) == before

            publish_scene(blank=True)
            response = request()
            assert response.success and not response.observation.pieces
            wait_for(lambda: len(observations) == before + 1)
            assert not observations[-1].pieces
            spin_for(0.3)
            log_files[1].seek(0)
            receiver_log = log_files[1].read()
            assert 'Vecteur recu : 4 piece(s)' in receiver_log, receiver_log
            assert 'Vecteur recu : 0 piece(s)' in receiver_log, receiver_log
            print('OK : service, trigger topic, TF, vecteur controleur, IDs, erreurs et scene vide.')
        except BaseException:
            for log in log_files:
                log.flush()
                log.seek(0)
                print(log.read())
            raise
        finally:
            for process in processes:
                if process.poll() is None:
                    os.killpg(process.pid, signal.SIGINT)
                    try:
                        process.wait(timeout=5)
                    except subprocess.TimeoutExpired:
                        os.killpg(process.pid, signal.SIGKILL)
                        process.wait()
            for log in log_files:
                log.close()
            for subscription in subscriptions:
                node.destroy_subscription(subscription)
            node.destroy_node()
            rclpy.shutdown()


if __name__ == '__main__':
    main()
