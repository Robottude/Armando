#include "Armed.h"

// define the variables to hold link lengths, joint angles, and end effector position
LinkLengths Lengths;
JointAngles Angles;
EndEffectorPosition Position;

void setup() {
  Serial.begin(9600); // initialize serial communication
  // set the link lengths
  Lengths.a1 = 10.0;  // value for link 1
  Lengths.a2 = 15.0;  // value for link 2
  Lengths.a3 = 20.0;  // value for link 3

  // set the joint angles
  Angles.theta1 = 1.5;  // value for joint 1 angle
  Angles.theta2 = 1.5;  // value for joint 2 angle 
  Angles.theta3 = 0;  // value for joint 3 angle
}

void loop() {
  Position=calculateForwardKinematics(Lengths, Angles);
  Serial.print("End Effector Position x: "); // verify the data
  Serial.println(Position.x);
  Serial.print("End Effector Position y: ");
  Serial.println(Position.y);
  Serial.print("End Effector Position z: ");
  Serial.println(Position.z);
  delay(5000);
}