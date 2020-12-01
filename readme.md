# COVID Test Collector
[![License](https://img.shields.io/badge/license-MIT-green)](https://opensource.org/licenses/MIT)
---
## Overview
This ROS based project simulate a robot that will locate a completed COVID test that has been randomly placed on a table by the patient. Once the robot has located the test vial, it will pick it up, carry it over to a collection bin, and safely place it in the bin.

## Dependencies
This program works on a device running Ubuntu 18.04 and ROS Melodic. It will also need Gazebo 7.x (part of ros-melodic-desktop-full package) and TIAGo robot packages. If full destop option was selecting while installing ROS kinetic, it is not required to install Gazebo separately.

* To install ROS Melodic in Ubuntu 18.04, follow the steps in this [link](http://wiki.ros.org/melodic/Installation/Ubuntu).

* To install catkin, follow the installation steps in this [link](http://wiki.ros.org/catkin).

## Dependencies
* This project assumses that you have turtlebot3_simulations installed:

```
cd ~/catkin_ws/src
git clone https://github.com/ROBOTIS-GIT/turtlebot3_simulations.git
```
* It also assumes the user has a created a catkin workspace by following this tutorial or you can follow the commands given further down this page under 'Build Instructions':
```
http://wiki.ros.org/catkin/Tutorials/create_a_workspace
```

## Build Instructions

To run this code in a catkin workspace:
```
cd ~/catkin_ws/
source devel/setup.bash
cd src/
git clone https://github.com/adigoswami/Covid_Test_Collector.git
cd ..
catkin_make
```
If you do not have a catkin workspace:
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
source devel/setup.bash
cd src/
git clone --recursive https://github.com/adigoswami/Covid_Test_Collector.git
cd ..
catkin_make
```
## Running

* After completing the building step, go to the workspace in the terminal and give the following commands.
```
cd ~/catkin_ws/
source devel/setup.bash
roslaunch Covid_Test_Collector collector.launch
```
The above command will automatically start the Gazebo application.

## Personnel
* Aditya Goswami, a roboticist working on his Masters at UMD.
* Divyam Garg, a roboticist working on his Masters at UMD.
* Loic Barret, a roboticist working on his Masters at UMD.