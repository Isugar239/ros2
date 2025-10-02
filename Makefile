SHELL := /usr/bin/bash

NUM ?= 1
XTERM ?= false

init:
	colcon build
	source install/setup.bash
	echo -e "\033[91mBUILDED \e[0m"

launch:
	echo -e "\033[91mSTARTING \e[0m"
	ros2 launch my_project_start start.launch.py

follow:
	source install/setup.bash && ros2 launch my_turtle_controller follow_with_teleop.launch.py

multi_follow:
	source install/setup.bash && ros2 launch my_turtle_controller multi_followers_with_teleop.launch.py num_followers:=$(NUM) use_xterm:=$(XTERM)