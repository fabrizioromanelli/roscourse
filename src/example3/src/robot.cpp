#include "ros/ros.h"
#include "example3/laser.h"

using namespace std;

void sensorCallback(const example3::laser::ConstPtr& msg)
{
  ROS_INFO("Msg timestamp   : [%u.%u]", msg->header.stamp.sec, msg->header.stamp.nsec);
  ROS_INFO("Start scan angle: %2.2f(rad) | End scan angle: %2.2f(rad) | Angle increment: %2.2f(rad)", msg->angle_min, msg->angle_max, msg->angle_increment);
  ROS_INFO("Minimum range   : %2.2f(m) | Maximum range: %2.2f(m)", msg->range_min, msg->range_max);

  for (auto it = msg->ranges.begin(); it != msg->ranges.end(); ++it)
  {
    if ( ((it - msg->ranges.begin()) % 20) == 0 && (it - msg->ranges.begin()) != 0 )
      cout << endl;
    cout << fixed << setw(4) << setprecision(2) << *it << " ";
  }
  cout << flush << endl;
}

int main(int argc, char **argv)
{
  // Inizializza ROS con un nodo denominato "robot"
  ros::init(argc, argv, "robot");

  ros::NodeHandle n;
  ros::Subscriber listener_sub = n.subscribe("sensorTopic", 1000, sensorCallback);

  ros::spin();

  return 0;
}
