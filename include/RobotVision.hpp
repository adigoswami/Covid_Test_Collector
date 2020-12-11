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
  void solve();
  void outputPose();
  fiducial_msgs::FiducialTransform ft;

 /**
  * contains private data members
  */ 
 private:
  ros::NodeHandle nh;

  ros::Subscriber scan_sub;

  tf2::Vector3 position;
  tf2::Quaternion q;

  void scanCallback(const fiducial_msgs::FiducialTransformArray::ConstPtr &msg);
};
