#!/usr/bin/env python3
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition, UnlessCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():

    use_xterm_arg = DeclareLaunchArgument(
        'use_xterm', default_value='false',
        description='Если true — запускать teleop в xterm, иначе в konsole.'
    )

    turtlesim = Node(
        package='turtlesim',
        executable='turtlesim_node',
        name='sim'
    )

    teleop_konsole = Node(
        condition=UnlessCondition(LaunchConfiguration('use_xterm')),
        package='turtlesim',
        executable='turtle_teleop_key',
        name='teleop',
        output='screen',
        prefix='konsole -e'
    )

    teleop_xterm = Node(
        condition=IfCondition(LaunchConfiguration('use_xterm')),
        package='turtlesim',
        executable='turtle_teleop_key',
        name='teleop_xterm',
        output='screen',
        prefix='xterm -e'
    )

    follower = Node(
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
    )

    return LaunchDescription([
        use_xterm_arg,
        turtlesim,
        teleop_konsole,
        teleop_xterm,
        follower,
    ])
