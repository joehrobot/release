#!/bin/bash

rostopic pub -1  /$AGV_NAME/plc_io_set std_msgs/Int16 16;
