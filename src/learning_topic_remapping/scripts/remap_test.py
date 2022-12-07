#!/usr/bin/env python3
import rospy
from std_msgs import String

if __name__ == "__main__":
    rospy.init_node("remap_test_py")

    # pub = rospy.Publisher("/chatter",String,queue_size=1000)
    # pub = rospy.Publisher("/chatter/money",String,queue_size=1000)
    
    # pub = rospy.Publisher("chatter",String,queue_size=1000)
    # pub = rospy.Publisher("chatter/money",String,queue_size=1000)

    # pub = rospy.Publisher("~chatter",String,queue_size=1000)
    pub = rospy.Publisher("~chatter/money",String,queue_size=1000)