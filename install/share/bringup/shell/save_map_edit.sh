#roslaunch bringup map_edit_saver.launch;
roscd bringup/param/;
rosrun map_server map_saver map:=map_edit;
rostopic pub -1 /shell_feedback std_msgs/String "save_map_edit";