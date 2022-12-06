#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "learning_api_cpp");

	ros::NodeHandle n;

	//ros::Publisher publisher = n.advertise<std_msgs::String>("/object_publisher", 10);
	ros::Publisher publisher = n.advertise<std_msgs::String>("/object_publisher", 10, true);

	ros::Rate loop_rate(5000);

	std_msgs::String msg;
	msg.data = "hello world";

	int count = 0;

	while (ros::ok())
	{
		while(count < 2)
		{
			publisher.publish(msg);
			count ++;
			ROS_INFO("I am publishing data!");
			loop_rate.sleep();
		}
	}

	return 0;
}