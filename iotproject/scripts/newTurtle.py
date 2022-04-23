#!/usr/bin/env python
import rospy
import sys, time
from geometry_msgs.msg import Twist
from std_msgs.msg import Int8

vel = rospy.Publisher('cmd_vel', Twist, queue_size = 1)
speed = 1

def callback(data):
	received_state = data.data
	return received_state

def main():
    state = rospy.Subscriber("rcommand", Int8, callback)
    
    if(state == 1):
        twist = Twist()
        x = 1
        y = 0
        z = 0
        turn = 0
        twist.linear.x = x*speed
        twist.linear.y = y*speed
        twist.linear.z = z*speed
        twist.angular.x = 0
        twist.angular.y = 0
        twist.angular.z = turn
        vel.publish(twist)
        
    elif(state == 2):
        twist = Twist()
        x = 1
        y = 0
        z = 0
        turn = 1
        twist.linear.x = x*speed
        twist.linear.y = y*speed
        twist.linear.z = z*speed
        twist.angular.x = 0
        twist.angular.y = 0
        twist.angular.z = turn
        vel.publish(twist)
    elif(state == 3):
        twist = Twist()
        x = 1
        y = 0
        z = 0
        turn = -1
        twist.linear.x = x*speed
        twist.linear.y = y*speed
        twist.linear.z = z*speed
        twist.angular.x = 0
        twist.angular.y = 0
        twist.angular.z = turn
        vel.publish(twist)
    elif(state == 4):
        twist = Twist()
        x = -1
        y = 0
        z = 0
        turn = 0
        twist.linear.x = x*speed
        twist.linear.y = y*speed
        twist.linear.z = z*speed
        twist.angular.x = 0
        twist.angular.y = 0
        twist.angular.z = turn
        vel.publish(twist)
        
    else:
        twist = Twist()
        x = 0
        y = 0
        z = 0
        turn = 0
        twist.linear.x = x*speed
        twist.linear.y = y*speed
        twist.linear.z = z*speed
        twist.angular.x = 0
        twist.angular.y = 0
        twist.angular.z = turn
        vel.publish(twist)
    
    rospy.init_node('LoraRosNetwork', anonymous=True)
	
	try:
		rospy.spin()
	except KeyboardInterrupt:
		print("Shutting down ROS")

if __name__ == '__main__':
	main()
		o