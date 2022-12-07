#!/usr/bin/env python3
import rospy

if __name__ == "__main__":
    rospy.set_param("/py_A",100)  # global
    rospy.set_param("py_B",100)  # relative
    rospy.set_param("~py_C",100)  # private