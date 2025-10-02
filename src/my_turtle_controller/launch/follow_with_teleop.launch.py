#!/usr/bin/env python3
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        # turtlesim
        Node(
            package='turtlesim',
            executable='turtlesim_node',
            name='sim'
        ),

        # teleop key для управления лидером (turtle1)
        Node(
            package='turtlesim',
            executable='turtle_teleop_key',
            name='teleop',
            output='screen',
            prefix='xterm -e'
        ),

        # наша нода: спаун ведомой и следование за лидером
        Node(
            package='my_turtle_controller',
            executable='turtle_follower_spawner',
            name='turtle_follower_spawner',
            parameters=[{
                'leader_name': 'turtle1',
                'follower_name': 'turtle2',
                'follower_x': 5.0,
                'follower_y': 5.0,
                'follower_theta': 0.0,
            }]
        ),
    ])


