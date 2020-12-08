#include <ros/ros.h>
#include <std_msgs/String.h>
#include <move_base_msgs/MoveBasActions.h>
#include <iostream>

class RobotNavigation {
    private:
     ros::Pubblisher pub;
     ros::Subscriber sub;
     move_base_msgs::MoveBaseGoal goal;

    public:
     RobotNavigation();
     void sendGoal();
}