// Motor.h

//  hardware control logic

#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
public:
    Motor(int stepPin, int dirPin, int stepsPerRevolution, int stepDelay);
    void setDirection(bool clockwise);
    void moveSteps(int steps);

private:
    int stepPin;
    int dirPin;
    int stepsPerRevolution;
    int stepDelay;
};

#endif  // MOTOR_H
