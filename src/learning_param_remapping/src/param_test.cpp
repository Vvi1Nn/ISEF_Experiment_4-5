#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"param_test");

    ros::param::set("/set_A",100); // global
    ros::param::set("set_B",100); // relative
    ros::param::set("~set_C",100); // private

    ros::NodeHandle nh;
    nh.setParam("/nh_A",100); // global

    nh.setParam("nh_B",100); // relative

    ros::NodeHandle nh_private("~");
    nh_private.setParam("nh_C",100); // private

    return 0;
}
