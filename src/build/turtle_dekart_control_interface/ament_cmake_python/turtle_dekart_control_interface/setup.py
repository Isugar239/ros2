from setuptools import find_packages
from setuptools import setup

setup(
    name='turtle_dekart_control_interface',
    version='0.0.0',
    packages=find_packages(
        include=('turtle_dekart_control_interface', 'turtle_dekart_control_interface.*')),
)
