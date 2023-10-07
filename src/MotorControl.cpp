// MotorControl.cpp
#include "MotorControl.h"

MotorControl::MotorControl() {}

void MotorControl::initServos() {
  // initialize servos
}

void MotorControl::moveToJointAngles(float joint_angles[3]) {
  // move servos to given joint angles
}

void MotorControl::moveToPosition(float position[3]) {
  // inverse kinematics to calculate joint angles and move servos
}