/* 
***Robottude/Armed
***UNIVERSAL ARDUINO ROBOT ARM LIBRARY

Functional, easy-to-use library for Robot Arm control. Includes Kinematic parameters analysis and hardware control.

MIT License

Copyright (c) [2023] [Robottude]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.		
*/

// MotorControl.h
// MotorControl.h
#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Servo.h>

#include <Servo.h>



typedef enum {
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_DEFECTOR_UP,
	MOVE_DEFECTOR_DOWN,	
  PASS,
}Moves;



class Motor {
  public:
    Motor(int pin1, int pin2, int pin3); // constructor
    void initialize(); // initialize the servos
    void moveJoint(int jointNumber, float angle); // move a single joint
    void moveJoints(float angle1, float angle2, float angle3); // move all joints
    void Motor::moveJoystick(Moves move, int *angle);
  private:
    Servo servo1;
    Servo servo2;
    Servo servo3;
    int servoPins[3];
};

#endif
