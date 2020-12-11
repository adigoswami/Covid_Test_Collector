/**
 * @file       control.cpp
 * @version    1.0
 * @brief      creates functionality to control methods
 * @created    20th Nov 2020
 * @copyright  Copyright 2020. All rights reserved
 * @Author :   Loic Barret 
 */

// user defined header files for control class
#include "../include/RobotVision.hpp"


/**
 * @brief control default constructor
 * @param none
 * @return none
 */
RobotVision::RobotVision() {
  init();
}

/**
 * @brief initializer to initialize publishers and subscrivers
 * @param none
 * @return none
 */
void RobotVision::init() {
  scan_sub = nh.subscribe("/fiducial_transforms", 1, &RobotVision::scanCallback, this);
}


/**
 * @brief callback that reads scanner measurements at 0deg, 30deg, and 330deg 
 * @param &msg the message being transcribed on the scan topic
 * @return none
 */
void RobotVision::scanCallback(const fiducial_msgs::FiducialTransformArray::ConstPtr &msg) {
  
  if (msg->transforms.size() > 0){
    ft = msg->transforms[0];
    seen = true;

  }

  //position.setValue(ft.transform.translation.x, ft.transform.translation.y, ft.transform.translation.z);
  //q.setValue(ft.transform.rotation.x, ft.transform.rotation.y, ft.transform.rotation.z, ft.transform.rotation.w);

}

fiducial_msgs::FiducialTransform RobotVision::getPose(){
  return ft;
}

