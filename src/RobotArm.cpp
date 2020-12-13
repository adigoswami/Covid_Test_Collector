// user defined header files for control class
#include "../include/RobotArm.hpp"

int RobotArm::moveArm(geometry_msgs::PoseStamped goal_pose){

  ros::AsyncSpinner spinner(1);
  spinner.start();
  
  goal_pose.header.frame_id = "base_footprint";

  std::vector<std::string> torso_arm_joint_names;
  //select group of joints
  moveit::planning_interface::MoveGroupInterface group_arm_torso("arm_torso");
  //choose your preferred planner
  group_arm_torso.setPlannerId("SBLkConfigDefault");
  group_arm_torso.setPoseReferenceFrame("base_footprint");
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
  spinner.stop();

  return 0;


}

void RobotArm::grip(){
  
  grip_goal.trajectory.joint_names.push_back("gripper_left_finger_joint");
  grip_goal.trajectory.joint_names.push_back("gripper_right_finger_joint");
  grip_goal.trajectory.points.resize(1);
  grip_goal.trajectory.points[0].positions.resize(2);
  grip_goal.trajectory.points[0].positions[0] = 0.0;
  grip_goal.trajectory.points[0].positions[1] = 0.0;
  grip_goal.trajectory.points[0].time_from_start = ros::Duration(4.0);

  grip_ac.sendGoal(grip_goal);
  grip_ac.waitForResult();

  if(grip_ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, goal was met");
  else
    ROS_INFO("The base failed to move to the goal");

}

void RobotArm::release(){
  
//  grip_goal.trajectory.joint_names.push_back("gripper_left_finger_joint");
  //grip_goal.trajectory.joint_names.push_back("gripper_right_finger_joint");
  //grip_goal.trajectory.points.resize(1);
  //grip_goal.trajectory.points[0].positions.resize(2);
  grip_goal.trajectory.points[0].positions[0] = 0.4;
  grip_goal.trajectory.points[0].positions[1] = 0.4;
  grip_goal.trajectory.points[0].time_from_start = ros::Duration(4.0);

  grip_ac.sendGoal(grip_goal);
  grip_ac.waitForResult();

  if(grip_ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, goal was met");
  else
    ROS_INFO("The base failed to move to the goal");

}