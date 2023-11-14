#include "Armed.h"

// define the servo pins
int servoPin1 = 9;
int servoPin2 = 10;
int servoPin3 = 11;

Motor Servos(servoPin1, servoPin2, servoPin3);

void setup() {
  // initialize the servos
  Servos.initialize();
}

void loop() {
  // move a single joint to a position
  Servos.moveJoint(1, 90);

  // move all joints to their respective positions
  Servos.moveJoints(45, 90, 135);
  
  delay(1000); // 1 second delay
}
