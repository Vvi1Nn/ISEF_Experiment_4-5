#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "learning_api_cpp");
	// ros::init(argc, argv, "learning_api", ros::init_options::AnonymousName);

	ros::NodeHandle n;

	ros::Publisher publisher = n.advertise<std_msgs::String>("/initialization", 10);

	ros::Rate loop_rate(5000);

	std_msgs::String msg;
	msg.data = "hello world";

	while (ros::ok())
	{
		publisher.publish(msg);
		ROS_INFO("I am publishing data!");
	    loop_rate.sleep();
	}

	return 0;
}