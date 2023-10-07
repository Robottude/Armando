// MotorControl.h
#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Servo.h>

class MotorControl {
public:
  MotorControl();
  void initServos();
  void moveToJointAngles(float joint_angles[3]);
  void moveToPosition(float position[3]);
private:
  Servo servos[3];
};

#endif