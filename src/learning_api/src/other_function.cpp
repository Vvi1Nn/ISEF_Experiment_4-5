#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "other_function");

    ros::NodeHandle n;

    int count = 0;

    ROS_DEBUG("hello, DEBUG"); // This type of message is not output to the terminal
    ROS_INFO("hello, INFO");
    ROS_WARN("Hello, WARN");
    ROS_ERROR("hello, ERROR");
    ROS_FATAL("hello, FATAL");

    while(ros::ok())
    {
        count ++;
        ROS_INFO("waiting...");
        if (count > 5)
            ros::shutdown();
    }

    return 0;
}