#!/bin/bash

rostopic pub -1 /scan_marker/trig std_msgs/Float64 '{"data":0.9}';
