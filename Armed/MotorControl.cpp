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


void Motor::moveJoystick(Moves move,int *angle){    //FOR MOVING USING JOYSTICK TYPE OF MOVE AND ARRAY OF ANGLES FOR ALL 3 SERVO M  
	
	switch(move){

		case MOVE_LEFT:
			servo1.write(angle[0]++);
		    break;
		
		case MOVE_RIGHT:
			servo1.write(angle[0]--);
	            break;
		
		case MOVE_UP:
			servo2.write(angle[1]++);   //+ OR - CHECK 
		    break;
		
		case MOVE_DOWN:
			servo1.write(angle[1]--);
		    break;
		    
		case MOVE_DEFECTOR_UP:
			servo3.write(angle[2]++);
		    break;
		    
		case MOVE_DEFECTOR_DOWN:
			servo3.write(angle[2]--);
		    break;
		 
		default:;	
	}
	
}


void Motor::sendAnglesToSerial(void){

   
    delay(1);
    Serial.write(servo1.read());
    delay(1);
    Serial.write(servo2.read());
    delay(1);
    Serial.write(servo3.read());
    delay(1);
    
  }
