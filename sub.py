#!/usr/bin/env python
import rospy
from std_msgs.msg import String
import MySQLdb
import serial
import time
'''
ser = serial.Serial('/dev/ttyUSB0',baudrate=9600)
if ser.isOpen():
     print(ser.name + ' is open...')

connection = MySQLdb.connect( host='localhost', user='root', passwd='rok', db='toll_collection' )

if(connection):
    print "connection eslablished" 
'''

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)
    new=data.data 
    cursor = connection.cursor()
    cursor.execute("SELECT Phone_number from user where customer_id=%s" % new)
    output = cursor.fetchone()
    print output[0]
    ser.write('at+cmgf=1'+'\n\r')
    time.sleep(2)
    ser.write("AT+CMGS=\"" + output[0] + "\" \n\r" )
    time.sleep(2)
    ser.write('This is an automatic message for toll collection')
    time.sleep(2)
    ser.write(chr(26)) 
    
def listener():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # node are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber("chatter", String, callback)



    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()
