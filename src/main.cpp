#include "../include/RobotNavigation.hpp"

int main(int argc char** argv){
  ros::init(argc, argv, "RobotNavigation");

  //> Creating Node handle.
  ros::NodeHandle n;

  //> Creating Walker walk object.
  RobotNavigation Robot(n);

  //> Waiting for scan msg call back.
  ros::spin();

  return 0;
}