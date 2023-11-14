
#include <math.h>

// forward kinematics calculates end effector's position in space (x, y, z) based on the given robot configuration (link lengths) and joint angles


typedef struct LinkLengths {
    double a1;
    double a2;
    double a3;
}LinkLengths;

typedef struct EndEffectorPosition {
    double x;
    double y;
    double z;
}EndEffectorPosition;

typedef struct JointAngles {
    double theta1;
    double theta2;
    double theta3;
}JointAngles;








// ForwardKinematics.cpp



EndEffectorPosition calculateForwardKinematics(LinkLengths linkLengths,JointAngles angles) {
    EndEffectorPosition position;

    double theta1 = angles.theta1; // Angle of joint 1
    double theta2 = angles.theta2; // Angle of joint 2
    double theta3 = angles.theta3; // Angle of joint 3

    // x and y value based on joint 1 rotation around the z axis
    double x = linkLengths.a1 * cos(theta1);
    double y = linkLengths.a1 * sin(theta1);


    // z value based on joint 2 and joint 3 for changes in z value
    double z = linkLengths.a1 + linkLengths.a2 * sin(theta2) + linkLengths.a3 * sin(theta2 + theta3);

    // update x and y values based on joint 2 and joint 3 change
    x += linkLengths.a2 * cos(theta1) * cos(theta2) + linkLengths.a3 * cos(theta1) * cos(theta2 + theta3);
    y += linkLengths.a2 * sin(theta1) * cos(theta2) + linkLengths.a3 * sin(theta1) * cos(theta2 + theta3);

    position.x = x;
    position.y = y;
    position.z = z;

    return position;
}



// InverseKinematics.cpp


// inverse kinematics calculates necessary joint values to achieve given end effector's position in space (x, y, z)

JointAngles calculateInverseKinematics(LinkLengths linkLengths,EndEffectorPosition position) {
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






