/* 
***Robottude/Armed
***UNIVERSAL ARDUINO ROBOT ARM LIBRARY

Functional, easy-to-use library for Robot Arm control. Includes Kinematic parameters analysis and hardware control.

MIT License

Copyright (c) [2023] [Robottude]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.		
*/

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