// Motor.cpp

// hardware control logic
#include "Motor.h"

Motor::Motor(int stepPin, int dirPin, int stepsPerRevolution, int stepDelay) {
    this->stepPin = stepPin;
    this->dirPin = dirPin;
    this->stepsPerRevolution = stepsPerRevolution;
    this->stepDelay = stepDelay;

    // initialize motor pins as out
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
}

void Motor::setDirection(bool clockwise) {
    digitalWrite(dirPin, clockwise ? HIGH : LOW);
}

void Motor::moveSteps(int steps) {
    for (int i = 0; i < abs(steps); ++i) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(stepDelay);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(stepDelay);
    }
}

