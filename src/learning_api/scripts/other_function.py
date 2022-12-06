#!/usr/bin/env python3

import rospy

def callback():
    print("shutdown ...")

if __name__ == '__main__':
    
    rospy.logdebug("hello, debug")
    rospy.loginfo("hello, info")
    rospy.logwarn("hello, warn")
    rospy.logerr("hello, error")
    rospy.logfatal("hello, fatal")

    count = 0

    while not rospy.is_shutdown():
        count = count + 1
        print(count)
        if count > 3:
            rospy.on_shutdown(callback)
            rospy.signal_shutdown("count = 3")