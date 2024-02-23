# Class: Motor

## Description:

The Motor class encapsulates the functionality for controlling Robot's servo motors. It provides simplified methods for initializing the motors and controlling individual and multiple joints.

## Member Functions:

### Constructor:

- `Motor(int pin1, int pin2, int pin3)`: Constructs a Motor object with the specified pin numbers for three servo motors.

### Initializer:

- `void initialize()`: Initializes all three servo motors attached to the specified pins with a single call.

### Joint Movement:

- `void moveJoint(int jointNumber, int angle)`: Moves a specific joint to the specified angle in degrees.

- `void moveJoints(int angle1, int angle2, int angle3)`: Moves all three joints to the specified angles in degrees simultaneously.

## Example:
```cpp
// Define the servo pins
int servoPin1 = 9;
int servoPin2 = 10;
int servoPin3 = 11;

// create a Motor object with servo pins
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
}
```
