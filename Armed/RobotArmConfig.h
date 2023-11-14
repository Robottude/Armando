// RobotArmConfig.h
#ifndef ROBOT_ARM_CONFIG_H
#define ROBOT_ARM_CONFIG_H

struct LinkLengths {
    double a1;
    double a2;
    double a3;
};

struct EndEffectorPosition {
    double x;
    double y;
    double z;
};

struct JointAngles {
    double theta1;
    double theta2;
    double theta3;
};

#endif
