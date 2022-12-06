#!/usr/bin/env python3

# chmod -x *.py
# ll

import rospy
from std_msgs.msg import String

if __name__ == '__main__':
    
    rospy.init_node('learning_api_py', anonymous = True)
    
    publisher = rospy.Publisher('initialization', String, queue_size = 10)
    
    msg = String()
    msg.data = 'hello_world'
    
    while not rospy.is_shutdown():
        
        publisher.publish(msg)
        
        print('I am publishing data!')