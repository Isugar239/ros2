#! /usr/bin/env python3
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    turtlesim_node = Node(
        package = 'turtlesim',
        executable = 'turtlesim_node',
        name = 'sim'
    )
    turtle_mover_node = Node(
        package = 'my_turtle_controller',
        executable = 'turtle_mover',
        name = 'turtle_mover'
    )
    return LaunchDescription([
        turtlesim_node,
        turtle_mover_node
    ])
    