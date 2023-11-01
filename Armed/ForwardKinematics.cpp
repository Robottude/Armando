// ForwardKinematics.cpp
#include "ForwardKinematics.h"
#include <math.h>

// forward kinematics calculates end effector's position in space (x, y, z) based on the given robot configuration (link lengths) and joint angles

EndEffectorPosition calculateForwardKinematics(const LinkLengths& linkLengths, const JointAngles& angles) {
    EndEffectorPosition position;

    double theta1 = angles.theta1; // Angle of joint 1
    double theta2 = angles.theta2; // Angle of joint 2
    double theta3 = angles.theta3; // Angle of joint 3

    // x and y value based on joint 1 rotation around the z axis
    double x = linkLengths.a1 * cos(theta1);
    double y = linkLengths.a1 * sin(theta1);

    // z value based on joint 2 and joint 3 for changes in z value
    double z = linkLengths.a2 * theta2 + linkLengths.a3 * theta3;

    // update x and y values based on joint 2 and joint 3 change
    x += linkLengths.a2 * cos(theta1) * cos(theta2) + linkLengths.a3 * cos(theta1) * cos(theta2 + theta3);
    y += linkLengths.a2 * sin(theta1) * cos(theta2) + linkLengths.a3 * sin(theta1) * cos(theta2 + theta3);

    position.x = x;
    position.y = y;
    position.z = z;

    return position;
}
