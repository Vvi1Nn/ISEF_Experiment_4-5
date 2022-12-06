#!/usr/bin/env python3

import rospy

def doMsg(event):
    rospy.loginfo("callback...")
    rospy.loginfo("Current time: %s", str(event.current_real))

if __name__ == '__main__':
    
    rospy.init_node('time_api_py')

    rospy.loginfo("---Moment---")

    rospy.loginfo("Current time: %.2f", rospy.Time.now().to_sec())
    rospy.loginfo("Current time: %.2f", rospy.Time.now().to_nsec())
    
    rospy.loginfo("Current time: %.2f", rospy.Time(1234.567891011).to_sec())
    rospy.loginfo("Current time: %.2f", rospy.Time(1234, 567891011).to_sec())

    rospy.loginfo("Current time: %.2f", rospy.Time.from_sec(543.21).to_sec())

    rospy.loginfo("---Duration of time---")

    rospy.loginfo("start...")
    du = rospy.Duration(3.3)
    rospy.loginfo("du1 time: %.2f", du.to_sec())
    rospy.sleep(du) #休眠函数
    rospy.loginfo("end...")

    rospy.loginfo("---Calculation of time---")

    now = rospy.Time.now()
    du1 = rospy.Duration(10)
    du2 = rospy.Duration(20)
    rospy.loginfo("Current time: %.2f", now.to_sec())
    before_now = now - du1
    after_now = now + du1
    dd = du1 + du2
    rospy.loginfo("before: %.2f", before_now.to_sec())
    rospy.loginfo("after: %.2f", after_now.to_sec())
    rospy.loginfo("addition: %.2f", dd.to_sec())

    rospy.loginfo("---Set frequency---")

    rate = rospy.Rate(0.5)
    count = 0
    while not rospy.is_shutdown():
        rate.sleep()
        rospy.loginfo("waiting...")
        count = count + 1
        if count > 3:
            break

    rospy.loginfo("---Timer---")

    rospy.Timer(rospy.Duration(1), doMsg)
    rospy.spin()