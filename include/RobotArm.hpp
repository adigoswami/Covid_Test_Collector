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


class RobotArm {
    private:
    	ros::NodeHandle nh;

    public:
        RobotArm();
        int moveArm(geometry_msgs::PoseStamped pose);
        geometry_msgs::PoseStamped safePose;
        
        
};