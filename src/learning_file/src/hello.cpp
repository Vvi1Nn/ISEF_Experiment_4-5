#include "ros/ros.h"
#include "learning_file/hello.h"

namespace hello_ns
{
    void HelloPub::run()
    {
        ROS_INFO("hello world !");
    }
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "learning_file_cpp");

    hello_ns::HelloPub helloPub;

    helloPub.run();

    return 0;
}