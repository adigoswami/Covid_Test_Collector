/**
 * @file       control.hpp
 * @version    1.0
 * @brief      Header file for control class.
 * @created    20th Nov 2020
 * @copyright  Copyright 2020. All rights reserved
 * @Author :   Loic Barret 
 */
#pragma once

// c++ header file
#include <ros/ros.h>
#include "fiducial_msgs/FiducialTransformArray.h"
#include <tf2/LinearMath/Transform.h>
#include <array>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <geometry_msgs/PoseStamped.h>


/**
 * creates the control class
 */
class RobotVision {
 /**
  * contains public data members
  */
 public:
  RobotVision();
  void init();
  void setPose();
  
  fiducial_msgs::FiducialTransform ft;
  geometry_msgs::PoseStamped object;
  geometry_msgs::PoseStamped object_above;
  geometry_msgs::PoseStamped object_in_grasp;
  bool seen = false;


 /**
  * contains private data members
  */ 
 private:
  ros::NodeHandle nh;

  ros::Subscriber scan_sub;

  void scanCallback(const fiducial_msgs::FiducialTransformArray::ConstPtr &msg);
};
