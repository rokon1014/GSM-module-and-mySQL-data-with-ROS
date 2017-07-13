#include "ros/ros.h"
#include "std_msgs/String.h"
#include <cstdio>
#include <sstream>
#include <mysql/mysql.h>


#define SERVER "localhost"
#define USER "root"
#define PASS "rok"
#define DATABASE "toll_collection"
 
 
using  namespace std;
 
MYSQL_RES* mysql_perform_query(MYSQL *connection, char *sql_query);
/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
 
    MYSQL *connection;  
    MYSQL_RES *result;  
    MYSQL_ROW row; 
 
    connection = mysql_init(NULL);
 
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
 
 
 
   */
 
connection = mysql_real_connect(connection, SERVER, USER, PASS, DATABASE, 0, NULL, 0);
 
 
if(connection)
{
 
  cout<< "connection successfull \n";
}
 
else
{
 
 cout<< "connection failed \n";
}
 
 //result = mysql_perform_query(connection, "SELECT * FROM MyGuests");
 
 
    if(mysql_query(connection, "SELECT Phone_number FROM user where customer_id=2"))  
    {  
        ROS_INFO("Query Error: %s", mysql_error(connection));  
        exit(1);  
    }  
    else 
    {  
 
        result = mysql_use_result(connection); 
        for(int i=0; i < mysql_field_count(connection); ++i)  
        {
            std::stringstream ss;  
            row = mysql_fetch_row(result);  
            if(row <= 0)  
            {  
                break;  
            }  
            for(int j=0; j < mysql_num_fields(result); ++j)  
            {  
                ss << row[j] << " ";  
            }  
            ROS_INFO("%s", ss.str().c_str());  
        }
        mysql_free_result(result);  
    }
 
 
 
 
 
 
/*
 
  ros::init(argc, argv, "talker");
 
 
  ros::NodeHandle n;
 
 
    
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
 
  ros::Rate loop_rate(10);
 
  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
 
/*
  int count = 0;
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
 
/*
    std_msgs::String msg;
 
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();
 
    ROS_INFO("%s", msg.data.c_str());
 
    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
 
/*
    chatter_pub.publish(msg);
 
    ros::spinOnce();
 
    loop_rate.sleep();
    ++count;
  }
*/
 
}
 
 
MYSQL_RES* mysql_perform_query(MYSQL *connection, char *sql_query)
{
   // send the query to the database
   if (mysql_query(connection, sql_query))
   {
      printf("MySQL query error : %s\n", mysql_error(connection));
      exit(1);
   }
  
   return mysql_use_result(connection);
}