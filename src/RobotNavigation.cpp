#include "../include/RobotNavigation.hpp"


RobotNavigation::RobotNavigation(ros::NodeHandle n)
    : pub(n.advertise<move_base_msgs::MoveBaseAction>("/move_base/goal", 10)),
      sub(n.subscribe("/topic", 10, &RobotNavigation::sendGoal, this)) {
        goal.target_pose.header.frame_id = "base_link";
        goal.target_pose.header.stamp = ros::Time::now();
        
        goal.target_pose.pose.position.x = 0.0;
        goal.target_pose.pose.orientation.w = 0.0;
        pub.Publish(goal);
      }
void RobotNavigation::sendGoal(const move_base_msgs::MoveBaseAction::ConstPtr &move){
    ROS_INFO("Goal pos to go is", move->target_pose->pos->position->x,"Goal orientation to be in is", move->target_pose->pose->orientation->w);
    // storing values of position.x and orientation.w from vision to move
    pub.Publish(goal);

}