#include <ros/ros.h>
#include "std_msgs/String.h"

void Callback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("AAA");
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "spin_function_cpp");

    ros::NodeHandle n;

    ros::Subscriber subscriber = n.subscribe("/initialization", 10, Callback);

    ros::spin();
    //ros::spinOnce();

    ROS_INFO("BBB");

    return 0;
}