// Motor.cpp

// hardware contorl logic

#include "Motor.h"

Motor::Motor(int stepsPerRev, int stepPin, int dirPin)
    : stepsPerRev(stepsPerRev), stepPin(stepPin), dirPin(dirPin), currentPosition(0), targetPosition(0), speed(100) {
}

void Motor::begin() {
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
}

void Motor::moveTo(int targetPosition) {
    // move motor implementation
}

