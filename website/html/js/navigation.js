"use strict";var PARAMS=PARAMS||{DefaultPose:{position:{x:0,y:0,z:0},orientation:{x:0,y:0,z:0,w:1}},CmdVel:.05,SailDis:.3,DockingBeginDis:.35,PowerWarnThreshold:.2,ChargeStatus:{uncontact:0,contact:1,volAbnormal:2,charging:3},NavCtrl:{stop:0,start:1,pause:2},NavCtrlStatus:{error:-1,idling:0,running:1,paused:2,completed:3,cancelled:4,sub_cancelled:5},NetworkMode:{ap:"ap",wifi:"wifi"},RobotStatus:{MappingStatus:"mappingStatus",LastNetworkSetting:"lastNetworkSetting"},Extensions:["ster","ster2","tofflon"],DiagnosticsLevel:{Warn:1,Error:2,Stale:3},NeedPoseTypes:["goal","pallet","mark","initial_pose"]},hood_block_time=0,NAV=NAV||{CmdEnum:{Navigation:"navigation",Gmapping:"gmapping",Cancel:"cancel",Converting:"converting",GamppingPose:"gmapping_pose",SaveMap:"save_map",SaveMapEdit:"save_map_edit",SaveAsMap:"save_as_map",SaveAsMapEdit:"save_as_map_edit",LoadMap:"load_map",LoadMapEdit:"load_map_edit",Userauth:"user_auth",MapSelect:"dbparam-select",MapDelete:"dbparam-delete",MapUpdate:"dbparam-update",MapInsert:"dbparam-insert",Update:"update",RoslogDelete:"roslog-delete",RoslogSelect:"roslog-select",Version:"version"},RosMode:{Gmapping:"gmapping",Navigation:"navigation",Converting:"converting"},WaypointMode:{Map:"map",Timer:"timer",Puber:"publisher",Suber:"subscriber",Pubsuber:"pubsuber",Looper:"looper",CmdVelSetSub:"cmd_vel_set_sub",CmdVel:"cmd_vel",Shell:"shell",SoundPlay:"sound_play",InitialPose:"initial_pose",ScanMaker:"scan_marker",ShellString:"shell_string",Pallet:"pallet"},SoundPlayMode:{Stop:"STOP",Start:"START",Once:"ONCE"},WaypointPrefix:{goal:"goal",timer:"timer",publisher:"pub",subscriber:"sub",looper:"loop",pubsuber:"pubsuber",cmd_vel_set_sub:"velSet",cmd_vel:"vel",shell:"shell",sound_play:"sound",initial_pose:"pose",scan_marker:"scanMarker",shell_string:"shellStr",pallet:"pallet"},ManualCtrlVel:{linear:.4,angular:.8},init:function(e){NAV.ros=new ROSLIB.Ros,NAV.ros.connect(e),NAV.ros.on("connection",function(){console.log("[INFO]Connected to rosbridge "+e+"."),DATA.ros=NAV.ros}),NAV.ros.on("close",function(){console.log("[INFO]Rosbridge server "+e+" closed."),ALERT.error({title:"网络错误",text:"Rosbridge连接失败"})}),NAV.ros.on("error",function(){console.error("[ERROR]Connection error.")})},withNs:function(e){var s=e.startsWith("/")?e:"/"+e;return"undefined"===DATA.namespace?s:DATA.namespace.startsWith("/")?DATA.namespace+s:"/"+DATA.namespace+s},getRobotStatus:function(){var e=new ROSLIB.Service({ros:NAV.ros,name:NAV.withNs("/rosnodejs/robot_status"),serviceType:"rosapi/SearchParam"}),s=new ROSLIB.ServiceRequest({name:""});e.callService(s,function(e){var s=JSON.parse(e.global_name);for(var a in s)switch(a){case"ros_mode":DATA.rosMode=s[a];break;case"network":DATA.lastNetworkSetting=s[a]}})},dispMapAndWps:function(e,s){var a=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs(e),messageType:"nav_msgs/OccupancyGrid"});s&&(DATA.useBase64=!0,a=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("map_stream"),messageType:"scheduling_msgs/MapStream"})),(DATA.topic.mapTopic=a).subscribe(function(e){DATA.mapMsg=e,NAV.dispWaypoints()})},dispWaypoints:function(){var e=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/waypoints"),messageType:"yocs_msgs/WaypointList"});(DATA.topic.waypointsTopic=e).subscribe(function(e){console.log("[INFO]Got waypoints"),DATA.waypointsMsg=e})},dispTrajectories:function(){new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/trajectories"),messageType:"yocs_msgs/TrajectoryList"}).subscribe(function(e){console.log("[INFO]Got trajectories."),DATA.trajectoriesMsg=e})},dispRobot:function(){var e=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/robot_pose"),messageType:"geometry_msgs/Pose"});(DATA.topic.robotPoseTopic=e).subscribe(function(e){DATA.robotPoseMsg=e})},dispGlobalPlan:function(){var e=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/move_base/NavfnROS/plan"),messageType:"nav_msgs/Path"});(DATA.topic.globalPlanTopic=e).subscribe(function(e){DATA.globalPlanMsg=e})},dispLocalPlan:function(){var e=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/move_base/DWAPlannerROS/local_plan"),messageType:"nav_msgs/Path"});(DATA.topic.localPlanTopic=e).subscribe(function(e){DATA.localPlanMsg=e})},dispFootprint:function(e){var s=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs(e||"/move_base/global_costmap/footprint"),messageType:"geometry_msgs/PolygonStamped"});(DATA.topic.footprintTopic=s).subscribe(function(e){DATA.footprintMsg=e})},dispLaserScan:function(){var e=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/scan_rectified"),messageType:"sensor_msgs/LaserScan",throttle_rate:200});(DATA.topic.laserScanTopic=e).subscribe(function(e){DATA.laserScanMsg=e})},dispLocalCostmap:function(){var s=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/move_base/local_costmap/costmap"),messageType:"nav_msgs/OccupancyGrid"});(DATA.topic.localCostmapTopic=s).subscribe(function(e){s.unsubscribe()})},listenTf:function(e){if(e=void 0===e||e){var s=new ROSLIB.TFClient({ros:NAV.ros,fixedFrame:"map",angularThres:.01,transThres:.01});s.subscribe("odom",function(e){DATA.tfMsg.map2odom={header:{stamp:null},transform:e}}),s.subscribe("base_footprint",function(e){DATA.tfMsg.map2base_footprint={header:{stamp:null},transform:e}}),s.subscribe("base_laser",function(e){DATA.tfMsg.map2base_laser={header:{stamp:null},transform:e}}),new ROSLIB.TFClient({ros:NAV.ros,fixedFrame:"base_link",angularThres:.01,transThres:.01}).subscribe("base_laser",function(e){DATA.tfMsg.base_link2base_laser={header:{stamp:null},transform:e}})}else{new ROSLIB.Topic({ros:NAV.ros,name:"/tf",messageType:"tf2_msgs/TFMessage"}).subscribe(function(e){for(var s=0;s<e.transforms.length;s++){var a=e.transforms[s].header.frame_id,t=e.transforms[s].child_frame_id;a.startsWith("/")&&(a=a.split("/")[1]),t.startsWith("/")&&(t=t.split("/")[1]);var o=a+"2"+t;DATA.tfMsg[o]=e.transforms[s]}})}},sendInitialPose:function(e){for(var s=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/initialpose"),messageType:"geometry_msgs/PoseWithCovarianceStamped"}),a=[],t=0;t<36;t++)a[t]=0;a[0]=.25,a[7]=.25,a[35]=Math.pow(Math.PI/12,2);var o=new ROSLIB.Message({header:{frame_id:"map"},pose:{pose:e,covariance:a}});s.publish(o),console.log("[INFO]setting initial pose")},subShellFeedback:function(){new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/shell_feedback"),messageType:"std_msgs/String"}).subscribe(function(e){switch(e.data){case"":break;default:var s=e.data.split(/[ :]/);switch(s[0].trim()){case"dbparam":DATA.mapList=s.slice(1);break;case"update":"update"===DATA.loading.key&&(DATA.loading=!1),"success"===s[1].trim()?ALERT.info({title:"软件更新",text:"更新成功"}):ALERT.error({title:"软件更新",text:"更新失败"})}}})},subDiagnostics:function(){new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/diagnostics_agg"),messageType:"diagnostic_msgs/DiagnosticArray"}).subscribe(function(e){for(var s=0;s<e.status.length;s++)e.status[s].name})},subShellFeedbackFromNodejs:function(){new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/rosnodejs/shell_feedback"),messageType:"std_msgs/String"}).subscribe(function(e){var s=e.data.split(":");if(1===s.length){var a=s[0].trim();console.log("ROS mode: "+a),DATA.rosMode=a}else if(2===s.length){var t=s[0].trim(),o=s[1].trim();switch(t){case"dbparam":DATA.mapList=o.split(" ");break;case"power":DATA.powerStatus=o.trim();break;case"charge":DATA.chargeStatus=o.trim();break;case"diagnostics":break;default:console.log("unknown "+t)}}})},subRosMode:function(){new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/ros_mode"),messageType:"std_msgs/String"}).subscribe(function(e){DATA.mappingStatus=e.data})},subMappingStatus:function(){new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/rosnodejs/mappingStatus"),messageType:"std_msgs/String"}).subscribe(function(e){})},subNavCtrlStatus:function(){new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/nav_ctrl_status"),messageType:"yocs_msgs/NavigationControlStatus"}).subscribe(function(e){DATA.navCtrlStatus=e})},subWaypointUserSub:function(){new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/waypoint_user_sub"),messageType:"std_msgs/String"}).subscribe(function(e){var s=e.data.indexOf(":"),a=e.data.substr(0,s).trim(),t=e.data.substring(s+1).trim();switch(a){case"read_status":DATA.plcStatus=t}})},subRobotStatus:function(){new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/rosnodejs/robot_status"),messageType:"std_msgs/String"}).subscribe(function(e){var s=JSON.parse(e.data);for(var a in s)switch(a){case"ros_mode":DATA.rosMode=s[a];break;case"power":var t=parseFloat(s[a]);DATA.powerStatus!==t&&(DATA.powerStatus=t);break;case"charge":var o=parseInt(s[a]);DATA.chargeStatus!==o&&(DATA.chargeStatus=o);break;case"diagnostics":var n=JSON.parse(s[a]);DATA.diagnosticsMsg=n}})},cmdStringTopic:function(){return new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/cmd_string"),messageType:"std_msgs/String"})},nodejsCmdStringTopic:function(){return new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/rosnodejs/cmd_string"),messageType:"std_msgs/String"})},waypointUserPubTopic:function(){return new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/waypoint_user_pub"),messageType:"std_msgs/String"})},pubCmdString:function(e,s){var a=s?NAV.nodejsCmdStringTopic():NAV.cmdStringTopic(),t=new ROSLIB.Message({data:e});a.publish(t)},pubMapEditObstacle:function(e){var s=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/rosnodejs/virtual_obstacle"),messageType:"geometry_msgs/Polygon"}),a=new ROSLIB.Message({points:e});s.publish(a)},saveMap:function(){console.log("[INFO]["+(new Date).getTime()+"]pub save map"),NAV.pubCmdString(NAV.CmdEnum.SaveMap,!0)},saveMapEdit:function(){console.log("[INFO]["+(new Date).getTime()+"]pub load map"),NAV.pubCmdString(NAV.CmdEnum.LoadMap),setTimeout(function(){console.log("[INFO]["+(new Date).getTime()+"]pub save map edit"),NAV.pubCmdString(NAV.CmdEnum.SaveMapEdit)},2e3)},addWaypoint:function(e){var s={close_enough:e.close_enough,goal_timeout:e.goal_timeout,failure_mode:e.failure_mode,type:e.type};e.frame_id&&(s.frame_id=e.frame_id),-1===PARAMS.NeedPoseTypes.indexOf(e.type)&&(e.pose={position:{x:0,y:0,z:0},orientation:{x:0,y:0,z:0,w:0}}),e.mark&&(s.mark=e.mark);var a=JSON.stringify(s),t=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/waypoint_add"),messageType:"yocs_msgs/Waypoint"}),o=new ROSLIB.Message({header:{frame_id:a},close_enough:e.close_enough,goal_timeout:e.goal_timeout,failure_mode:e.failure_mode,name:e.name,pose:e.pose});t.publish(o),console.log("[INFO]waypoint added")},delWaypoint:function(e){var s=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/waypoint_remove"),messageType:"yocs_msgs/Waypoint"}),a=getWaypointByName(e),t=new ROSLIB.Message(a);s.publish(t)},addTrajectory:function(e,s){for(var a=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/trajectory_add"),messageType:"yocs_msgs/Trajectory"}),t=[],o=0;o<s.length;o++){var n=s[o];t.push(getWaypointByName(n))}var r=new ROSLIB.Message({name:e,waypoints:t});a.publish(r)},delTrajectory:function(e){var s=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/trajectory_remove"),messageType:"yocs_msgs/Trajectory"}),a=getTrajectoryByName(e),t=new ROSLIB.Message(a);s.publish(t)},addWaypointsForDock:function(){for(var e in NAV.WaypointsForDock)if("scanMarker_scan"!==e)NAV.addWaypoint(NAV.WaypointsForDock[e]);else for(var s=9;3<s;s--){var a={};(a=$.extend(a,NAV.WaypointsForDock[e])).name+="_"+s,a.close_enough=.1*s,NAV.addWaypoint(a)}},addTrajForDock:function(){var e=setInterval(function(){0!==DATA.waypointsMsg.waypoints.length&&("timer_sail"===DATA.waypointsMsg.waypoints[DATA.waypointsMsg.waypoints.length-1].name&&(NAV.addTrajectory(NAV.DockingBeginTrajName,NAV.DockingBegin),DATA.dockInitPoseName&&(NAV.DockingEnd[0]=DATA.dockInitPoseName,NAV.addTrajectory(NAV.DockingEndTrajName,NAV.DockingEnd)),clearInterval(e),e=null,console.log("[INFO]trajectories for docking added")))},500)},navCtrl:function(e,s){var a=!1;if(!0===(arguments.length<=2?void 0:arguments[2])&&(a=!0),a||DATA.navCtrlStatus.status===PARAMS.NavCtrlStatus.idling||s!==PARAMS.NavCtrl.start){var t=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/nav_ctrl"),messageType:"yocs_msgs/NavigationControl"}),o=new ROSLIB.Message({goal_name:e,control:s});console.log("[INFO]pub "+e+", "+s),t.publish(o)}else ALERT.warn({title:"导航中",text:"正在执行其他任务，当前命令将被忽略"})},manipulateScene:function(e,s,a){var t=e+":"+s;a?NAV.pubCmdString(t,!0):NAV.pubCmdString(t)},manualCtrl:function(e){var s=e.linear||0,a=e.angular||0,t=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/cmd_vel"),messageType:"geometry_msgs/Twist"}),o=new ROSLIB.Message({linear:{x:s,y:0,z:0},angular:{x:0,y:0,z:a}});DATA.manualCtrlTimer&&(clearInterval(DATA.manualCtrlTimer),DATA.manualCtrlTimer=null),0!==s||0!==a?DATA.manualCtrlTimer=setInterval(function(){t.publish(o)},200):t.publish(o)},subLastNetworkSetting:function(){new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/rosnodejs/last_network_setting"),messageType:"std_msgs/String"}).subscribe(function(e){DATA.lastNetworkSetting=e})},setNetwork:function(e,s){var a=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/rosnodejs/network"),messageType:"std_msgs/String"});s.mode=e;var t=JSON.stringify(s),o=new ROSLIB.Message({data:t});a.publish(o)},update:function(e,s){var a="";switch(e){case UpdateEvent.Type.onlineAuto:return void NAV.pubCmdString(s);case UpdateEvent.Type.offlineAuto:a="/shell_string";break;case UpdateEvent.Type.others.dbparam:a="/system_shell/shell_string";break;case UpdateEvent.Type.others.openssh:a="/shell_string";break;default:return void console.error("[ERROR]unknown update mode: "+e)}var t=new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs(a),messageType:"std_msgs/String"}),o=new ROSLIB.Message({data:s});t.publish(o)},moveBaseStatus:function(){new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/move_base/status"),messageType:"actionlib_msgs/GoalStatusArray"}).subscribe(function(e){if("4"==e.status_list[0].status){var s=(new Date).getSeconds();s-hood_block_time<1&&(document.getElementById("hood").style.display="block"),hood_block_time=s}else{30<(new Date).getSeconds()-hood_block_time&&(document.getElementById("hood").style.display="none")}})},subPowerByWayPointUserSub:function(){new ROSLIB.Topic({ros:NAV.ros,name:NAV.withNs("/waypoint_user_sub"),messageType:"std_msgs/String"}).subscribe(function(e){if(e.data){var s=e.data.split(":")[0].trim(),a=e.data.split(":")[1].trim();switch(s){case"power":case"power_yihe":var t=a.split(",")[0].trim(),o=a.split(",")[1].trim();n(parseInt(t),parseInt(o))}}function n(e,s){var a=String.fromCharCode(e),t=String.fromCharCode(s);return 16*parseInt(a,16)+parseInt(t,16)}})}};function getWaypointByName(e){for(var s=0;s<DATA.waypointsMsg.waypoints.length;s++){var a=DATA.waypointsMsg.waypoints[s];if(a.name===e)return a}}function getTrajectoryByName(e){for(var s,a=0;a<DATA.trajectoriesMsg.trajectories.length&&(s=DATA.trajectoriesMsg.trajectories[a]).name!==e;a++);return s}function isNameUsed(e){if(DATA.waypointsMsg)for(var s=0;s<DATA.waypointsMsg.waypoints.length;s++)if(DATA.waypointsMsg.waypoints[s].name===e)return!0;if(DATA.trajectoriesMsg)for(s=0;s<DATA.trajectoriesMsg.trajectories.length;s++)if(DATA.trajectoriesMsg.trajectories[s].name===e)return!0;return!1}