from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='sorting',
            executable='sorting_node',
            name='sorting',
            output='screen',
            parameters=[{'enabled_at_startup': False}],
        ),
    ])