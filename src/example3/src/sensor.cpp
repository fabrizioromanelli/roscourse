#include "ros/ros.h"
#include "example3/laser.h" // Including message for laser (autogenerated)
#include <sstream>

int main(int argc, char **argv)
{
  // Inizializza ROS con un nodo denominato "laser_scanner"
  ros::init(argc, argv, "laser_scanner");

  ros::NodeHandle n;
  ros::Publisher laser_pub = n.advertise<example3::laser>("sensorTopic", 1000);
  ros::Rate loop_rate(40);

  example3::laser msg;

  // Scan range
  msg.angle_min = -0.79; // -45°
  msg.angle_max = 0.79;  // +45°
  msg.angle_increment = 0.01; // 0.9° - distanza angolare tra le misure

  msg.range_min = 0.2; // 0.2 m è il range minimo
  msg.range_max = 30;  // 30 m è il range massimo

  size_t vectorSize = fabs(msg.angle_max + fabs(msg.angle_min)) / msg.angle_increment + 1;
  msg.ranges.resize(vectorSize);

  std::vector<short> sign;
  sign.resize(vectorSize);

  // Initializzazione laser range con valori random tra range_min e range_max
  for (auto it = msg.ranges.begin(); it != msg.ranges.end(); ++it)
  {
    srand (static_cast <unsigned> (ros::Time::now().nsec));
    float r = msg.range_min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(msg.range_max - msg.range_min)));
    msg.ranges[it - msg.ranges.begin()] = r;
    sign[it - msg.ranges.begin()] = 1;
  }

  while (ros::ok())
  {
    msg.header.stamp = ros::Time::now();
    ROS_INFO("Header timestamp: %u.%u", msg.header.stamp.sec, msg.header.stamp.nsec);

    for (auto it = msg.ranges.begin(); it != msg.ranges.end(); ++it)
    {
      size_t idx = it - msg.ranges.begin();
      srand (static_cast <unsigned> (ros::Time::now().nsec));
      float r = static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/0.2));

      if (msg.ranges[idx] >= msg.range_max)
        sign[idx] = -1;

      if (msg.ranges[idx] <= msg.range_min)
        sign[idx] = 1;

      msg.ranges[idx] = msg.ranges[idx] + sign[idx] * r; // è il valore in metri degli scan per ogni incremento
    }

    laser_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }
  return 0;
}
