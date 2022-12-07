#include <ros/ros.h>
#include "std_msgs/String.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"remap_test");
    // ros::NodeHandle n;

    // global
    // ros::Publisher pub = n.advertise<std_msgs::String>("/111", 10);
    // ros::Publisher pub = n.advertise<std_msgs::String>("/zwh/111", 10);

    // relative
    // ros::Publisher pub = n.advertise<std_msgs::String>("111", 10);
    // ros::Publisher pub = n.advertise<std_msgs::String>("zwh/111", 10);

    // private
    ros::NodeHandle nh("~");
    // ros::Publisher pub = nh.advertise<std_msgs::String>("111", 10);
    // ros::Publisher pub = nh.advertise<std_msgs::String>("zwh/111",1000);
    ros::Publisher pub = nh.advertise<std_msgs::String>("/zwh/111",1000);

    while(ros::ok())
    {
        ROS_INFO("publishing...");
    }
    return 0;
}
