# robotont_battery
Package robotont_battery consists of arduino publisher (publishes values of each battery`s cell voltages) and ROS subscriber-publisher node (receives and publishes converted values as BatteryState messages).
## How to obtain values that describe state of the battery?
#### 1. Build the package `battery` in the catkin workspace and source the setup.*sh file:
    catkin build 
    source devel/setup.bash 

