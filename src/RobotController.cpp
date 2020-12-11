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

  tiagovid_navigator.sendGoal(1.5, -4.0, -M_PI/2);
  while(ros::ok()){

    // Move to first goal
    tiagovid_navigator.sendGoal(.1, -7.0, M_PI);
    ROS_INFO("Checking for Object");
    int i = 0;
    while(ros::ok()) {
      if(tiagovid_vision.seen || i > 20){
        break;
      }
      loop_rate.sleep();
      ros::spinOnce();
      ++i;
    }
    if (tiagovid_vision.seen){
      std::cout << "found";
      break;
    }


    tiagovid_navigator.sendGoal(.1, -9.0, M_PI);
    ROS_INFO("Checking for Object");
    i = 0;
    while(ros::ok()) {
      if(tiagovid_vision.seen || i > 20){
        break;
      }
      loop_rate.sleep();
      ros::spinOnce();
      ++i;
    }
    if (tiagovid_vision.seen){
      std::cout << "found";
      break;
    }

    //Move to 3rd table
    tiagovid_navigator.sendGoal(.1, -11.0, M_PI);

    //check for object
    ROS_INFO("Checking for Object");
    i = 0;
    while(ros::ok()) {
      if(tiagovid_vision.seen || i > 20){
        break;
      }
      loop_rate.sleep();
      ros::spinOnce();
      ++i;
    }
    if (tiagovid_vision.seen){
      std::cout << "found";
      break;
    }    
  }



  return 0;
}