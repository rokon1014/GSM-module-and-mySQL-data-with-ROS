#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import String
import MySQLdb
import serial
import time


ser = serial.Serial('/dev/ttyUSB0',baudrate=9600)
if ser.isOpen():
     print(ser.name + ' is open...')
'''
connection = MySQLdb.connect( host='localhost', user='root', passwd='rok', db='toll_collection' )

if(connection):
    print "connection eslablished" 

cursor = connection.cursor()
cursor.execute("SELECT Phone_number from user where customer_id=2 ")
data = cursor.fetchone()

print data
number="01719338349"
ser.write('at+cmgf=1'+'\n\r')
time.sleep(2)
#ser.write('atd'+number+'\n\r')

ser.write("AT+CMGS=\"" + number + "\" \n\r" )
time.sleep(2)
ser.write('something')
time.sleep(2)
ser.write(chr(26)) 
'''
number='5'

def talker():
    pub = rospy.Publisher('chatter', String, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        hello_str = "sdfdsklfjdskj"
        rospy.loginfo(number)
        pub.publish(number)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass