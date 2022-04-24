#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist
from std_msgs.msg import Int8

state = 2
twistmsg = Twist
def callback(data):
	global state
	rospy.loginfo(data.data)
	state = data.data
	


def move(state):
    
    rospy.init_node('LoRaROSNetwork', anonymous = True)
    vel = rospy.Publisher('/turtle1/cmd_vel', twistmsg, queue_size = 100)
    speed = 1
    twist = twistmsg()
    
    if(state == 1):
        twist.linear.x = 1
        twist.linear.y = 0
        twist.linear.z = 0
        twist.angular.x = 0
        twist.angular.y = 0
        twist.angular.z = 0
        vel.publish(twist)
        
    elif(state == 2):
        twist.linear.x = 1
        twist.linear.y = 0
        twist.linear.z = 0
        twist.angular.x = 0
        twist.angular.y = 0
        twist.angular.z = 1
        vel.publish(twist)
    elif(state == 3):
        twist.linear.x = 1
        twist.linear.y = 0
        twist.linear.z = 0
        twist.angular.x = 0
        twist.angular.y = 0
        twist.angular.z = -1
        vel.publish(twist)
    elif(state == 4):
        twist.linear.x = -1
        twist.linear.y = 0
        twist.linear.z = 0
        twist.angular.x = 0
        twist.angular.y = 0
        twist.angular.z = 0
        vel.publish(twist)
        
    else:
        twist.linear.x = 0
        twist.linear.y = 0
        twist.linear.z = 0
        twist.angular.x = 0
        twist.angular.y = 0
        twist.angular.z = 0
        vel.publish(twist)
    rate = rospy.Rate(10)
    rate.sleep()
    
    
def main():
	global state
	rospy.Subscriber('/rcommand', Int8, callback) 
	
	while(1):
		move(state)
	
	rospy.spin()

if __name__ == '__main__':
	try:
		main()
	except rospy.ROSInterruptException:
		pass
