#!/usr/bin/env python3
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.conditions import IfCondition, UnlessCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def _generate_followers(context):
    num_followers_str = LaunchConfiguration('num_followers').perform(context)
    try:
        num_followers = int(num_followers_str)
    except ValueError:
        num_followers = 1

    leader_name = LaunchConfiguration('leader_name').perform(context)

    follower_nodes = []
    # follower turtles: turtle2, turtle3, ...
    for i in range(2, 2 + max(0, num_followers)):
        follower_nodes.append(
            Node(
                package='my_turtle_controller',
                executable='turtle_follower_spawner',
                name=f'turtle_follower_spawner_{i}',
                parameters=[{
                    'leader_name': leader_name,
                    'follower_name': f'turtle{i}',
                }]
            )
        )
    return follower_nodes


def generate_launch_description():
    num_followers_arg = DeclareLaunchArgument(
        'num_followers', default_value='1',
        description='Сколько ведомых черепашек заспаунить (turtle2..).'
    )
    leader_name_arg = DeclareLaunchArgument(
        'leader_name', default_value='turtle1',
        description='Имя ведущей черепахи, которой управляем стрелками.'
    )
    use_xterm_arg = DeclareLaunchArgument(
        'use_xterm', default_value='false',
        description='Если true — запускать teleop в xterm, иначе в konsole.'
    )
    # Всегда открываем teleop в отдельном окне konsole

    turtlesim_node = Node(
        package='turtlesim',
        executable='turtlesim_node',
        name='sim'
    )

    teleop_in_konsole = Node(
        condition=UnlessCondition(LaunchConfiguration('use_xterm')),
        package='turtlesim',
        executable='turtle_teleop_key',
        name='teleop_konsole',
        output='screen',
        prefix='konsole -e'
    )

    teleop_in_xterm = Node(
        condition=IfCondition(LaunchConfiguration('use_xterm')),
        package='turtlesim',
        executable='turtle_teleop_key',
        name='teleop_xterm',
        output='screen',
        prefix='xterm -e'
    )

    followers = OpaqueFunction(function=_generate_followers)

    return LaunchDescription([
        num_followers_arg,
        leader_name_arg,
        turtlesim_node,
        teleop_in_konsole,
        teleop_in_xterm,
        followers,
    ])


