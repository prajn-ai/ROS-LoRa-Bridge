#!/usr/bin/env python
import rospy
import sys, time
from geometry_msgs.msg import Twist
from std_msgs.msg import Int8

state = 0
x = 0
y = 0
z = 0

speed = 1
turn = 0

vel = rospy.Publisher('cmd_vel', Twist, queue_size = 1)

def callback(data):
	received_state = data.data
	return received_state

def update(x, y, z, turn, speed):
	x = x
	y = y
	z = z
	turn = turn
	run(x, y, z, turn, speed)
	
def run(x, y, z, turn, speed):
	twist = Twist()
	twist.linear.x = x*speed
	twist.linear.y = y*speed
	twist.linear.z = z*speed
	twist.angular.x = 0
	twist.angular.y = 0
	twist.angular.z = turn
	
	vel.publish(twist)

def rest():
	update(0, 0, 0, 0, 0)

def forward():
	update(1, 0, 0, 0, 1)

def left():
	update(1, 0, 0, 1, 1)

def right():
	updtae(1, 0, 0 , -1, 1)

def backward():
	update(-1, 0, 0, 0, 1)


def runNetwork():
	state = rospy.Subscriber("rcommand", Int8, callback)
	
	
	if(state == 1):
		forward()
	elif(state == 2):
		left()
	elif(state == 3):
		backward()
	elif(state == 4):
		right()
	else:
		rest()
		
def main(args):
	rospy.init_node('LoraRosNetwork', anonymous=True)
	run = runNetwork()
	
	try:
		rospy.spin()
	except KeyboardInterrupt:
		print("Shutting down ROS")

if __name__ == '__main__':
	main(sys.argv)
		

