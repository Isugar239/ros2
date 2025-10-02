SHELL := /usr/bin/bash

init:
	colcon build
	source install/setup.bash
	echo "builed"