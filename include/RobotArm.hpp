// ROS headers
#include <ros/ros.h>

// MoveIt! headers
#include <moveit/move_group_interface/move_group_interface.h>

// Std C++ headers
#include <string>
#include <vector>
#include "fiducial_msgs/FiducialTransformArray.h"
#include <map>

class RobotArm {
    private:
    	ros::NodeHandle nh;

    public:
        RobotArm();
        void moveArm(fiducial_msgs::FiducialTransform pose);
        
};