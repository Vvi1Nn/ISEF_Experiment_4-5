#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char *argv[])
{
    std::map<std::string, std::string> map;
    map["__ns"] = "mynamespace";
    ros::init(map,"mynode");
    ros::NodeHandle n;
    while(ros::ok())
    {
        ROS_INFO("namespace.cpp");
    }
    return 0;
}