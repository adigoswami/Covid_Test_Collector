// user defined header files for control class
#include "../include/RobotArm.hpp"

RobotArm::RobotArm(){}

void RobotArm::moveArm(fiducial_msgs::FiducialTransform pose){
  geometry_msgs::PoseStamped goal_pose;
  goal_pose.header.frame_id = "map";

  
  goal_pose.pose.position.x = pose.transform.translation.x;
  goal_pose.pose.position.y = pose.transform.translation.y;
  goal_pose.pose.position.z = pose.transform.translation.z;
  goal_pose.pose.orientation = pose.transform.rotation;

  std::vector<std::string> torso_arm_joint_names;
  //select group of joints
  moveit::planning_interface::MoveGroupInterface group_arm_torso("arm_torso");
  //choose your preferred planner
  group_arm_torso.setPlannerId("SBLkConfigDefault");
  group_arm_torso.setPoseReferenceFrame("map");
  group_arm_torso.setPoseTarget(goal_pose);

  ROS_INFO_STREAM("Planning to move " <<
                  group_arm_torso.getEndEffectorLink() << " to a target pose expressed in " <<
                  group_arm_torso.getPlanningFrame());

  group_arm_torso.setStartStateToCurrentState();
  group_arm_torso.setMaxVelocityScalingFactor(1.0);


  moveit::planning_interface::MoveGroupInterface::Plan my_plan;
  //set maximum time to find a plan
  group_arm_torso.setPlanningTime(5.0);


  ROS_INFO_STREAM("Plan found in " << my_plan.planning_time_ << " seconds");

  // Execute the plan
  ros::Time start = ros::Time::now();

  group_arm_torso.move();

  ROS_INFO_STREAM("Motion duration: " << (ros::Time::now() - start).toSec());

}