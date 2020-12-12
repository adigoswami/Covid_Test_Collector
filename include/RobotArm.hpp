// ROS headers
#include <ros/ros.h>

// MoveIt! headers
#include <moveit/move_group_interface/move_group_interface.h>

// Std C++ headers
#include <string>
#include <vector>
#include "fiducial_msgs/FiducialTransformArray.h"
#include <map>
#include <geometry_msgs/PoseStamped.h>
#include <actionlib/client/simple_action_client.h>
#include <control_msgs/FollowJointTrajectoryAction.h>

typedef actionlib::SimpleActionClient<control_msgs::FollowJointTrajectoryAction> joint_control_client;

class RobotArm {
    private:
    	ros::NodeHandle nh;

    public:
        RobotArm() : grip_ac("/gripper_controller/follow_joint_trajectory"){
            ROS_INFO("Waiting for action server to start.");
            grip_ac.waitForServer();
            ROS_INFO("Action server started");
            safePose.pose.position.x = 0.363;
            safePose.pose.position.y = -0.197;
            safePose.pose.position.z = 1.0;
            safePose.pose.orientation.x = 0.707;
            safePose.pose.orientation.y = 0;
            safePose.pose.orientation.z = 0;
            safePose.pose.orientation.w = 0.707;
        }
        int moveArm(geometry_msgs::PoseStamped pose);
        geometry_msgs::PoseStamped safePose;
        void grip();
        joint_control_client grip_ac;
        control_msgs::FollowJointTrajectoryGoal grip_goal;


        
};
