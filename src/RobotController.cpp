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
#include "../include/RobotArm.hpp"
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
  RobotArm tiagovid_arm;

  /**
   * define what rate we want the loop to run at
   */
  ros::Rate loop_rate(10);

  /**
   * while loop that will drive the turtlebot around at the rate 
   * defined above until ros shuts down
   */

  tiagovid_arm.moveArm(tiagovid_arm.safePose);
  tiagovid_navigator.sendGoal(1.5, -4.0, -M_PI/2);
  ros::Duration(1).sleep();

  while(ros::ok()){

    // Move to first goal
    tiagovid_navigator.sendGoal(1.25, -7.0, M_PI);
    ros::Duration(1).sleep();
    tiagovid_navigator.sendGoal(0.5, -7.0, M_PI);
    ros::Duration(2).sleep();
    ROS_INFO("Checking for Object");
    int i = 0;
    while(ros::ok()) {
      
      loop_rate.sleep();
      ros::spinOnce();
      ++i;
      if(tiagovid_vision.seen || i > 20){
        break;
      }
    }
    if (tiagovid_vision.seen){
      std::cout << "found";
      break;
    }


    tiagovid_navigator.sendGoal(1.25, -9.0, M_PI);
    ros::Duration(1).sleep();
    tiagovid_navigator.sendGoal(0.5, -9.0, M_PI);
    ros::Duration(2).sleep();
    ROS_INFO("Checking for Object");
    i = 0;
    while(ros::ok()) {
      
      loop_rate.sleep();
      ros::spinOnce();
      ++i;
      if(tiagovid_vision.seen || i > 20){
        break;
      }
    }
    if (tiagovid_vision.seen){
      std::cout << "found";
      break;
    }

    //Move to 3rd table
    tiagovid_navigator.sendGoal(1.25, -11.0, M_PI);
    ros::Duration(1).sleep();
    tiagovid_navigator.sendGoal(0.5, -11.0, M_PI);
    ros::Duration(2).sleep();
    //check for object
    ROS_INFO("Checking for Object");
    i = 0;
    while(ros::ok()) {

      loop_rate.sleep();
      ros::spinOnce();
      ++i;
      if(tiagovid_vision.seen || i > 20){
        break;
      }
    }
    if (tiagovid_vision.seen){
      std::cout << "found";
      break;
    }    
  }
  tiagovid_vision.setPose();

  tiagovid_arm.moveArm(tiagovid_vision.object_above);
  tiagovid_arm.moveArm(tiagovid_vision.object_in_grasp);
  tiagovid_arm.grip();
  tiagovid_arm.moveArm(tiagovid_arm.safePose);
  tiagovid_navigator.sendGoal(0.0, 0.0, M_PI);
  tiagovid_navigator.sendGoal(-2.5, .5, M_PI/2);
  tiagovid_arm.moveArm(tiagovid_arm.collectPose);
  tiagovid_arm.release();

  return 0;
}