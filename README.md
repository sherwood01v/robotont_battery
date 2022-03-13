# robotont_battery
Package robotont_battery consists of arduino publisher (publishes values of each battery`s cell voltages) and ROS subscriber-publisher node (receives and publishes converted values as BatteryState messages).
## How to obtain values that describe state of the battery?
#### 1. Build the package `battery` in the catkin workspace and source the setup.*sh file:
    catkin build 
    source devel/setup.bash
#### 2. Setup the Arduino IDE, connect to the Arduino, upload the code to Arduino:
Tutorial how to setup Arduino IDE and add rosserial library is [here](http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup).</br>
**2.1 Open the code arduino_publisher.ino in the directory ~/battery/scripts/arduino_publisher/**</br>
>NB! Check the Tools-Board-"Arduino Nano"</br>
>Check the Tools-Processor-"ATmega328P (Old Bootloader)"</br>
>If you connected to Arduino through USB, check USB port: Tools-Port</br>

**Upload the code to Arduino: Sketch-Upload**
