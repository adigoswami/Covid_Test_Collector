// user defined header files for control class
#include "../include/RobotArm.hpp"

RobotArm::RobotArm(){
  safePose.pose.position.x = 0.363;
  safePose.pose.position.y = -0.197;
  safePose.pose.position.z = 1.0;
  safePose.pose.orientation.x = 0.707;
  safePose.pose.orientation.y = 0;
  safePose.pose.orientation.z = 0;
  safePose.pose.orientation.w = 0.707; 
}

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