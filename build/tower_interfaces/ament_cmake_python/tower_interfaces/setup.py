from setuptools import find_packages
from setuptools import setup

setup(
    name='tower_interfaces',
    version='0.1.0',
    packages=find_packages(
        include=('tower_interfaces', 'tower_interfaces.*')),
)
