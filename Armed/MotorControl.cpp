// MotorControl.cpp
#include "MotorControl.h"

Motor::Motor(int pin1, int pin2, int pin3) {
  servoPins[0] = pin1;
  servoPins[1] = pin2;
  servoPins[2] = pin3;
}

void Motor::initialize() {
  servo1.attach(servoPins[0]);
  servo2.attach(servoPins[1]);
  servo3.attach(servoPins[2]);
}

void Motor::moveJoint(int jointNumber, int angle) {
  if (jointNumber == 1) {
    servo1.write(angle);
  } else if (jointNumber == 2) {
    servo2.write(angle);
  } else if (jointNumber == 3) {
    servo3.write(angle);
  }
}

void Motor::moveJoints(int angle1, int angle2, int angle3) {
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
}