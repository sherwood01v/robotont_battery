#include <ros.h>
#include <std_msgs/Float32MultiArray.h>
int sensorPins[] = { A0, A1, A2, A3 };
float sensorValues[] = { 0, 0, 0, 0 };

ros::NodeHandle nh;

std_msgs::Float32MultiArray arduino_msg;
ros::Publisher pub_arduino("arduino_values", &arduino_msg);

void setup() {
  pinMode(sensorPins[0], INPUT);
  pinMode(sensorPins[1], INPUT);
  pinMode(sensorPins[2], INPUT);
  pinMode(sensorPins[3], INPUT);
  nh.initNode();
  nh.advertise(pub_arduino);
  arduino_msg.data = (float*)malloc(sizeof(float) * 4);
  arduino_msg.data_length = 4;
}

void loop() {
  // read the value from the sensor:
  sensorValues[0] = analogRead(sensorPins[0])/814.0*3.74;
  sensorValues[1] = analogRead(sensorPins[1])/947.0*7.57 - analogRead(sensorPins[0])/814.0*3.74;
  sensorValues[2] = analogRead(sensorPins[2])/950.0*11.36 - analogRead(sensorPins[1])/947.0*7.57;
  sensorValues[3] = analogRead(sensorPins[3])/919.0*15.14 - analogRead(sensorPins[2])/950.0*11.36;
  sensorValues;

  for (int i = 0; i<4; ++i)
  {
    arduino_msg.data[i] = sensorValues[i];
  }
  
  pub_arduino.publish(&arduino_msg);  
  nh.spinOnce();
  delay(1000);
}
