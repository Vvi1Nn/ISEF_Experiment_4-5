#!/usr/bin/env python3

import rospy
from std_msgs.msg import String

def Callback(msg):
    rospy.loginfo("AAA")

if __name__ == '__main__':
    
    rospy.init_node('learning_api_py', anonymous = True)
    
    subscriber = rospy.Subscriber('/initialization', String, Callback)

    rospy.spin()

    rospy.loginfo("BBB")