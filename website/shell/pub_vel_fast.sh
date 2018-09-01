#!/bin/bash

rosrun dynamic_reconfigure dynparam set /move_base/DWAPlannerROS max_trans_vel 0.55;
rosrun dynamic_reconfigure dynparam set /move_base/DWAPlannerROS max_vel_x 0.55;

rosrun dynamic_reconfigure dynparam set /move_base/DWAPlannerROS path_distance_bias 96.0;
