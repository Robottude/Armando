// MotorControl.cpp
#include "MotorControl.h"

#define M_PI 3.14159265358979323846

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

void Motor::moveJoint(int jointNumber, float angle) {
int angleDeg = static_cast<int>(angle * 180.0 / M_PI); // radians to degrees
  if (jointNumber == 1) {
    servo1.write(angleDeg);
  } else if (jointNumber == 2) {
    servo2.write(angleDeg);
  } else if (jointNumber == 3) {
    servo3.write(angleDeg);
  }
}

void Motor::moveJoints(float angle1, float angle2, float angle3) {
  int angle1Deg = static_cast<int>(angle1 * 180.0 / M_PI);
  int angle2Deg = static_cast<int>(angle2 * 180.0 / M_PI);
  int angle3Deg = static_cast<int>(angle3 * 180.0 / M_PI);
  servo1.write(angle1Deg);
  servo2.write(angle2Deg);
  servo3.write(angle3Deg);
}