#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"remap",ros::init_options::AnonymousName);
    ros::NodeHandle n;
    while(ros::ok())
    {
        ROS_INFO("remap.cpp");
    }
    return 0;
}