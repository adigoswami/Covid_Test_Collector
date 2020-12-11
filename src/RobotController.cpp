/**
 * @file walker_node.cpp
 * @version 1.0
 * @brief Ros node that controls the turtlebot 
 * @Created on: Nov 20, 2020
 * @copyright 2020 
 * @Author Loic Barret
 */

#include "../include/RobotNavigation.hpp"
#include "../include/RobotVision.hpp"
#include <math.h>


int main(int argc, char **argv) {
  /**
   * initialize the ros node
   */
  ros::init(argc, argv, "tiagovid_controller");

  /**
   * create a navigator object
   */
  RobotNavigation tiagovid_navigator;
  RobotVision tiagovid_vision;

  /**
   * define what rate we want the loop to run at
   */
  ros::Rate loop_rate(10);

  /**
   * while loop that will drive the turtlebot around at the rate 
   * defined above until ros shuts down
   */
  while(ros::ok()) {
    ROS_INFO("checking for marker");
    std::cout << tiagovid_vision.ft.transform.translation.x;
    loop_rate.sleep();
    ros::spinOnce();
  }
  //tiagovid_navigator.sendGoal(1.5, -4.0, -M_PI/2);
  //tiagovid_navigator.sendGoal(0, -7.0, M_PI);

  //tiagovid_navigator.sendGoal(0, -9.0, M_PI);
  
  ros::spinOnce();


  return 0;
}