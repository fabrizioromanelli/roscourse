# roscourse

Some examples for ROS lessons.
The project contains several examples and 3 packages.

* example1: this example contains a single node called _publisher_ which publish String messages @ 10Hz.
* example2: this example contains two nodes (_talker_ and _listener_). The _talker_ node publishes messages @ 10Hz and the _listener_ node subscribes to the _talkTopic_ and spin over a callback to write on console the received messages.
* example3: this example contains two nodes (_sensor_ and _robot_). The node called _sensor_ publishes messages @ 40Hz with the data of the laser readings: ```angle_min```, ```angle_max``` and ```angle_increment``` are the start and end angle of the scan and the angular distance between measurements in radians, ```range_min``` and ```range_max``` represents the minimum and maximum range values in meters while ```ranges[]``` is an array containing the ranges data for all the scanned area in meters.
