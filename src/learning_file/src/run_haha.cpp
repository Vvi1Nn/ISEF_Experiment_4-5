#include "ros/ros.h"
#include "learning_file/haha.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"learning_file");
    hello_ns::My my;
    my.run();
    return 0;
}
