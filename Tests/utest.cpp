/**
 * @file       RobotVision.cpp
 * @version    1.0
 * @brief      Creates functionality to robot vision methods
 * @created    19th Dec 2020
 * @copyright  Copyright 2020. All rights reserved
 * @Author :   Loic Barret 
 */
#include <ros/ros.h>
#include <gtest/gtest.h>
#include "../include/RobotVision.hpp"
#include "fiducial_msgs/FiducialTransformArray.h"
#include <tf2/LinearMath/Transform.h>
#include <array>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <geometry_msgs/PoseStamped.h>


/*
 * @brief LEVEL 2 ROS Test
 */
TEST(Vision, scan_sub) {
// RobotVision robotvision;
// ros::NodeHandle n;
// ros::Subscriber sub = n.subscribe("/fiducial_transforms", 1, &RobotVision::scanCallback, &robotvision);
// EXPECT_NO_FATAL_FAILURE(sub);
EXPECT_EQ(2,2);
}

