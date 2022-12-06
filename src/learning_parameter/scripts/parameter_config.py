#!/usr/bin/env python

import sys
import rospy
from std_srvs.srv import Empty

def parameter_config():

    rospy.init_node('parameter_config', anonymous=True)

    red   = rospy.get_param('/background_r')
    green = rospy.get_param('/background_g')
    blue  = rospy.get_param('/background_b')

    rospy.loginfo("Get Backgroud Color[%d, %d, %d]", red, green, blue)

    rospy.set_param("/background_r", 255)
    rospy.set_param("/background_g", 255)
    rospy.set_param("/background_b", 255)

    rospy.loginfo("Set Backgroud Color[255, 255, 255]")

    red   = rospy.get_param('/background_r')
    green = rospy.get_param('/background_g')
    blue  = rospy.get_param('/background_b')

    rospy.loginfo("Get Backgroud Color[%d, %d, %d]", red, green, blue)

    rospy.wait_for_service('/clear')
    try:
        clear_background = rospy.ServiceProxy('/clear', Empty)

		# 请求服务调用，输入请求数据
        response = clear_background()
        return response
    except rospy.ServiceException as e:
        print ("Service call failed: %s" % e)

if __name__ == "__main__":
    parameter_config()