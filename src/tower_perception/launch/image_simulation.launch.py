"""Simulation a partir d'une image ou d'une scene generee, sans materiel."""

from pathlib import Path

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, EmitEvent, OpaqueFunction, RegisterEventHandler
from launch.conditions import IfCondition
from launch.event_handlers import OnProcessExit
from launch.events import Shutdown
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import yaml


def create_nodes(context):
    config_path = LaunchConfiguration('config').perform(context)
    with open(config_path, encoding='utf-8') as stream:
        parameters = yaml.safe_load(stream)['perception_node']['ros__parameters']
    # La camera virtuelle est verticale ; tous les echanges restent sous /simulation.
    perception = Node(
        package='tower_perception', executable='perception_node',
        namespace='simulation', name='perception_node', output='screen',
        parameters=[parameters, {
            'color_topic': '/simulation/color',
            'depth_topic': '/simulation/depth',
            'camera_info_topic': '/simulation/camera_info',
            'output_frame': '', 'table_normal_camera': [0.0, 0.0, -1.0],
        }],
        remappings=[
            ('/detected_pieces', '/simulation/detected_pieces'),
            ('/perception/analyze_image', '/simulation/perception/analyze_image'),
            ('/perception/analyze', '/simulation/perception/analyze'),
            ('/perception/debug_image', '/simulation/perception/debug_image'),
        ],
    )
    source = Node(
        package='tower_perception', executable='image_simulator',
        namespace='simulation', name='image_simulator', output='screen',
        parameters=[{
            'config_path': config_path,
            'image_path': LaunchConfiguration('image').perform(context),
            'output_dir': LaunchConfiguration('output_dir').perform(context),
            'depth_m': float(LaunchConfiguration('depth_m').perform(context)),
            'fx': float(LaunchConfiguration('fx').perform(context)),
            'fy': float(LaunchConfiguration('fy').perform(context)),
            'cx': float(LaunchConfiguration('cx').perform(context)),
            'cy': float(LaunchConfiguration('cy').perform(context)),
            'once': LaunchConfiguration('once').perform(context).lower() == 'true',
            'auto_analyze': LaunchConfiguration('auto_analyze').perform(context).lower() == 'true',
            'wait_for_controller': LaunchConfiguration('start_controller').perform(context).lower() == 'true',
        }],
    )
    controller = Node(
        package='tower_control', executable='tower_controller',
        namespace='simulation', name='tower_controller', output='screen',
        condition=IfCondition(LaunchConfiguration('start_controller')),
        remappings=[('/detected_pieces', '/simulation/detected_pieces')],
    )
    # Arreter proprement les autres noeuds a la fin du mode once ou en cas d'echec.
    shutdown_handlers = [RegisterEventHandler(OnProcessExit(
        target_action=process,
        on_exit=[EmitEvent(event=Shutdown(reason='Fin de la simulation image'))],
    )) for process in (source, perception)]
    return [*shutdown_handlers, perception, source, controller]


def generate_launch_description():
    config = str(Path(get_package_share_directory('tower_perception')) / 'config/perception.yaml')
    return LaunchDescription([
        DeclareLaunchArgument('image', default_value='', description='PNG/JPG ; vide = scene generee'),
        DeclareLaunchArgument('config', default_value=config),
        DeclareLaunchArgument('output_dir', default_value='simulation_output'),
        DeclareLaunchArgument('depth_m', default_value='0.8',
                              description='Distance virtuelle du support, ou profondeur uniforme pour une image fournie'),
        DeclareLaunchArgument('fx', default_value='800.0'),
        DeclareLaunchArgument('fy', default_value='800.0'),
        DeclareLaunchArgument('cx', default_value='-1.0', description='-1 = centre de l image'),
        DeclareLaunchArgument('cy', default_value='-1.0', description='-1 = centre de l image'),
        DeclareLaunchArgument('once', default_value='false', description='Arreter apres un resultat sauvegarde'),
        DeclareLaunchArgument('auto_analyze', default_value='true'),
        DeclareLaunchArgument('start_controller', default_value='true'),
        OpaqueFunction(function=create_nodes),
    ])
