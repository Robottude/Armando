// MotorControl.h
#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Servo.h>

#include <Servo.h>

class Motor {
  public:
    Motor(int pin1, int pin2, int pin3); // constructor
    void initialize(); // initialize the servos
    void moveJoint(int jointNumber, float angle); // move a single joint
    void moveJoints(float angle1, float angle2, float angle3); // move all joints

  private:
    Servo servo1;
    Servo servo2;
    Servo servo3;
    int servoPins[3];
};

#endif