// ForwardKinematics.cpp
#include "ForwardKinematics.h"
#include <math.h>

EndEffectorPosition calculateForwardKinematics(const LinkLengths& linkLengths, const JointAngles& angles) {
    EndEffectorPosition position;

    double theta1 = angles.theta1;
    double theta2 = angles.theta2;
    double theta3 = angles.theta3;

    // end effector position in the xy plane
    double x = linkLengths.a1 * cos(theta1) + linkLengths.a2 * cos(theta1 + theta2);
    double y = linkLengths.a1 * sin(theta1) + linkLengths.a2 * sin(theta1 + theta2);

    // end effector position in the z axis
    double z = linkLengths.a1 * sin(theta3) + linkLengths.a2 * sin(theta2 - theta3);

    position.x = x;
    position.y = y;
    position.z = z;

    return position;
}
