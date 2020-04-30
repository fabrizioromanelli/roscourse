#include "ros/ros.h"
#include "std_msgs/String.h"

void talkerCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("Ho ricevuto: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  // Inizializza ROS con un nodo denominato "listener"
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;
  ros::Subscriber listener_sub = n.subscribe("talkTopic", 1000, talkerCallback);

  ros::spin();

  return 0;
}
