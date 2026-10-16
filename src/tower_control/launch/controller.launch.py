from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='tower_control',
            executable='tower_controller',
            output='screen',
        ),
    ])
