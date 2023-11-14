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
    double z = linkLengths.a1 + linkLengths.a2 * sin(theta2) + linkLengths.a3 * sin(theta2 + theta3);

    // update x and y values based on joint 2 and joint 3 change
    x += linkLengths.a2 * cos(theta1) * cos(theta2) + linkLengths.a3 * cos(theta1) * cos(theta2 + theta3);
    y += linkLengths.a2 * sin(theta1) * cos(theta2) + linkLengths.a3 * sin(theta1) * cos(theta2 + theta3);

    position.x = x;
    position.y = y;
    position.z = z;

    return position;
}
