#!/usr/bin/env python3
import rospy

if __name__ == "__main__":
    rospy.init_node("remap_py", anonymous=True)
    while not rospy.is_shutdown():
        rospy.loginfo("remap")