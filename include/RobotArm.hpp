#include <ros/ros.h>
#include <std_msgs/String.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <actionlib/client/simple_action_client.h>
#include <iostream>
#include "fiducial_msgs/FiducialTransformArray.h"
#include <tf2/LinearMath/Transform.h>


class RobotArm {
    private:
    	ros::NodeHandle nh;
        ros::Publisher arm_goal_pub;
        geometry_msgs::PoseStamped goal_pose;

    public:
        RobotArm();
        void moveArm(fiducial_msgs::FiducialTransform pose);
        
};