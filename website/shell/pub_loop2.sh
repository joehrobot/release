#!/bin/bash

rosrun dynamic_reconfigure dynparam set /sick_tim571 max_ang 0.50;
rosrun dynamic_reconfigure dynparam set /sick_tim571 min_ang -0.50;
