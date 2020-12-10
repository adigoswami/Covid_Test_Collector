#include "../include/RobotNavigation.hpp"
#include <tf2/LinearMath/Quaternion.h>


void RobotNavigation::sendGoal(double x, double y, double w){
    while(!ac.waitForServer(ros::Duration(5.0))){
      ROS_INFO("Waiting for the move_base action server to come up");
    }
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();
    tf2::Quaternion myQuaternion;
    myQuaternion.setRPY(0, 0, w);

    goal.target_pose.pose.position.x = x;
    goal.target_pose.pose.position.y = y;

    goal.target_pose.pose.orientation.x = myQuaternion[0];
    goal.target_pose.pose.orientation.y = myQuaternion[1];
    goal.target_pose.pose.orientation.z = myQuaternion[2];
    goal.target_pose.pose.orientation.w = myQuaternion[3];
    ROS_INFO_STREAM("Goal pos to go is " << goal.target_pose.pose.position.x << 
    	", " << goal.target_pose.pose.position.y <<
    	"\nGoal orientation to be in is " << goal.target_pose.pose.orientation.w);
    // storing values of position.x and orientation.w from vision to move
    ac.sendGoal(goal);

    ac.waitForResult();

    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
      ROS_INFO("Hooray, the base moved 1 meter forward");
    else
      ROS_INFO("The base failed to move forward 1 meter for some reason");

}

