#!/usr/bin/env python3

import rospy
from std_msgs.msg import String

if __name__ == '__main__':
    
    rospy.init_node('learning_api_py', anonymous = True)
    
    publisher = rospy.Publisher('object_publisher', String, queue_size = 10)
    # publisher = rospy.Publisher('object_publisher', String, queue_size = 10, latch = True)
    
    msg = String()
    msg.data = 'hello_world'

    count = 0
    
    while not rospy.is_shutdown():
        while count < 2:
            publisher.publish(msg)
            count = count + 1
            print('I am publishing data!')