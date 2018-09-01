#!/bin/bash
rosrun dynamic_reconfigure dynparam set /scan_filter/box_left min_y 0.25;
rosrun dynamic_reconfigure dynparam set /scan_filter/box_left max_y 0.35;
rosrun dynamic_reconfigure dynparam set /scan_filter/box_right min_y -0.35;
rosrun dynamic_reconfigure dynparam set /scan_filter/box_right max_y -0.25;