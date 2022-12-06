#include "ros/ros.h"

void callback(const ros::TimerEvent &event)
{
    ROS_INFO("callback");
    ROS_INFO("event: %.5f", event.current_real.toSec());
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "learning_api_cpp");

    ros::NodeHandle n; // initialize time api

    ROS_INFO("---Moment---");

    ros::Time current_time = ros::Time::now();
    ROS_INFO("Current time 1: %d", current_time.sec);
    ROS_INFO("Current time 1: %.2f", current_time.toSec());
    
    ros::Time someTime1(100,100000000); // s, ns
    ROS_INFO("Current time 1: %.2f",someTime1.toSec()); // 100.10
    ros::Time someTime2(100.3); // s
    ROS_INFO("Current time 1: %.2f",someTime2.toSec()); // 100.30

    ROS_INFO("---Duration of time---");

    ROS_INFO("Current time 2: %.2f", ros::Time::now().toSec());
    ros::Duration du(3);// s
    du.sleep();
    ROS_INFO("Current time 2: %.2f", du.toSec());
    ROS_INFO("Current time 2: %.2f", ros::Time::now().toSec());

    ROS_INFO("---Calculation of time---");

    ros::Time now = ros::Time::now();
    ros::Duration du1(1);
    ros::Duration du2(3);
    ROS_INFO("Current time 3: %.2f", now.toSec());

    // Calculation between time and duration
    ros::Time after_now = now + du1;
    ROS_INFO("After: %.2f", after_now.toSec());
    ros::Time before_now = now - du1;
    ROS_INFO("Before: %.2f", before_now.toSec());

    // Calculation between duration and duration
    ros::Duration du3 = du1 + du2;
    ros::Duration du4 = du1 - du2;
    ROS_INFO("du3 = %.2f", du3.toSec());
    ROS_INFO("du4 = %.2f", du4.toSec());

    // PS: CANNOT CALCULATE BETWEEN TIME AND TIME
    // ros::Time nn = now + before_now; // error

    ROS_INFO("---Set frequency---");

    ros::Rate rate(1); // frequency
    int count = 0;
    while (count < 3)
    {
        ROS_INFO("Waiting... %d", count);
        count ++;
        rate.sleep(); // time = 1 / frequency
    }

    ROS_INFO("---Timer---");

    ros::Timer timer = n.createTimer(ros::Duration(0.5), callback, true, false);
    timer.start();
    ros::spin();

    return 0;
}