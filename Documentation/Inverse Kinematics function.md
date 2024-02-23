# Function: calculateInverseKinematics

## Description:

The calculateInverseKinematics function computes the necessary joint values to achieve a given end effector's position in space (x, y, z). It employs inverse kinematics principles to determine the joint angles required for the robot manipulator to reach the specified end effector position. 
The function begins by extracting the Cartesian coordinates (x, y, z) of the end effector from the input position structure. It then proceeds to compute the joint angles necessary for the robot manipulator to reach this position using trigonometric and geometric constraints. It calculates the rotation angle around the z-axis (theta1), the angle between the end effector and joint 1 (theta2), and the angle between joints 2 and 3 (theta3). These calculations are based on the lengths of the robot's links (a1, a2, and a3) and the specified end effector position.

### Parameters:

- `linkLengths (Type: LinkLengths)`: A structure containing the lengths of the robot's links, including a1, a2, and a3.

- `position (Type: EndEffectorPosition)`: A structure representing the position of the end effector in space, including x, y, and z coordinates.

### Returns:

- `angles (Type: JointAngles)`: A structure representing the calculated joint angles required to achieve the specified end effector position.

## Example:
```cpp
LinkLengths lengths = {1.0, 0.8, 0.6}; // Example link lengths
EndEffectorPosition position = {2.0, 1.5, 0.0}; // Example end effector position
JointAngles angles = calculateInverseKinematics(lengths, position);
// angles.theta1, angles.theta2, and angles.theta3 now contain the calculated joint angles
```
