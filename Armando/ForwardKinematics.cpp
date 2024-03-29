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


// define maximum and minimum angles for the servos (0 to 180 degrees)
const double MAX_ANGLE = M_PI; // 180 degrees in radians
const double MIN_ANGLE = 0.0; // 0 degrees in radians

// ensure angle is within the range of servo movement
double limitAngle(double angle) {
    if (angle > MAX_ANGLE) {
        return MAX_ANGLE;
    } else if (angle < MIN_ANGLE) {
        return MIN_ANGLE;
    }
    return angle;
}

// forward kinematics calculates end effector's position in space (x, y, z) based on the given robot configuration (link lengths) and joint angles

EndEffectorPosition calculateForwardKinematics(const LinkLengths& linkLengths, const JointAngles& angles) {
    EndEffectorPosition position;

    double theta1 = limitAngle(angles.theta1); // joint 1
    double theta2 = limitAngle(angles.theta2); // joint 2
    double theta3 = limitAngle(angles.theta3); // joint 3

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

// calculating upper and lower bounds in space due to geometry and servo constraints (maximum and minimum values of x, y and z)
WorkspaceBounds calculateWorkspaceBounds(const LinkLengths& lengths, int resolution) {
    const double pi = 3.14159265359;
    const double step_size = pi / resolution;
    JointAngles angles;
    WorkspaceBounds bounds;
    bounds.minX = bounds.minY = bounds.minZ = 1e20; // A large number as an initial placeholder
    bounds.maxX = bounds.maxY = bounds.maxZ = -1e20; // A small number as an initial placeholder

    for (angles.theta1 = 0; angles.theta1 <= pi; angles.theta1 += step_size) {
        for (angles.theta2 = 0; angles.theta2 <= pi; angles.theta2 += step_size) {
            for (angles.theta3 = 0; angles.theta3 <= pi; angles.theta3 += step_size) {
                // Calculate end effector position using forward kinematics
		EndEffectorPosition position = calculateForwardKinematics(lengths, angles);

                // Update workspace bounds
                bounds.minX = minimum(bounds.minX, position.x);
                bounds.maxX = maximum(bounds.maxX, position.x);
                bounds.minY = minimum(bounds.minY, position.y);
                bounds.maxY = maximum(bounds.maxY, position.y);
                bounds.minZ = minimum(bounds.minZ, position.z);
                bounds.maxZ = maximum(bounds.maxZ, position.z);
            }
        }
    }

    return bounds;
}

double minimum(double a, double b) {
    return (a < b) ? a : b;
}

double maximum(double a, double b) {
    return (a > b) ? a : b;
}