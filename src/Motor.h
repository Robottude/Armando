// Motor.h

//  hardware control logic

#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
public:
    Motor(int stepsPerRev, int stepPin, int dirPin);

    void begin();
    void moveTo(int targetPosition);

private:
    int stepsPerRev;
    int stepPin;
    int dirPin;
    int currentPosition;
    int targetPosition;
    int speed;
};

#endif
