// InverseKinematics.cpp
#include "InverseKinematics.h"
#include <math.h>

// inverse kinematics calculates necessary joint values to achieve given end effector's position in space (x, y, z)

JointAngles calculateInverseKinematics(const LinkLengths& linkLengths, const EndEffectorPosition& position) {
    JointAngles angles;

    double x = position.x;
    double y = position.y;
    double z = position.z;

    // rotation around the z-axis
    angles.theta1 = atan2(y, x);

    // the distance between joint 1 and the end effector in the xy plane
    double r_xy = sqrt(x * x + y * y);

    // the distance between joint 1 and the end effector in space
    double r = sqrt(r_xy * r_xy + z * z);

    // joint 3 sine and cosine
    double cosTheta3 = (linkLengths.a2 * linkLengths.a2 + linkLengths.a3 * linkLengths.a3 - r * r) / (2 * linkLengths.a2 * linkLengths.a3);
    double sinTheta3 = -sqrt(1 - cosTheta3 * cosTheta3); // Use negative sign for this configuration

    // joint 3 value
    angles.theta3 = atan2(sinTheta3, cosTheta3);

    // intermediate angle for joint 2 calculation
    double alpha = atan2(z, r_xy);

    // joint 2 cosine
    double cosTheta2 = (r * r + linkLengths.a2 * linkLengths.a2 - linkLengths.a3 * linkLengths.a3) / (2 * r * linkLengths.a2);

    // joint 2 value
    angles.theta2 = alpha - atan2(sqrt(1 - cosTheta2 * cosTheta2), cosTheta2);

    return angles;
}