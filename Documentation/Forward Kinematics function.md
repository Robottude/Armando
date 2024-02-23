# Function: calculateForwardKinematics

## Description:

The calculateForwardKinematics function computes the end effector's position in space (x, y, z) based on the given robot configuration, including link lengths and joint angles. It employs forward kinematics principles to determine the spatial coordinates of the end effector relative to the robot's base frame.
The function utilizes trigonometric relationships to compute the end effector's position based on the specified joint angles and link lengths. It begins by limiting the joint angles to ensure they fall within the permissible range of motion for the robot's servos. Subsequently, it calculates the Cartesian coordinates (x, y) of the end effector in the robot's base frame, considering the rotation of the joints around the z-axis. The function then determines the z-coordinate by incorporating changes in joint angles and link lengths. Finally, it updates the x, y, and z coordinates to account for additional changes resulting from joint rotations.

### Parameters:

linkLengths (Type: LinkLengths): A structure containing the lengths of the robot's links, including a1, a2, and a3.

angles (Type: JointAngles): A structure representing the joint angles of the robot, including theta1, theta2, and theta3.

### Returns:

position (Type: EndEffectorPosition): A structure representing the position of the end effector in space, including x, y, and z coordinates.

## Example:
```cpp
LinkLengths lengths = {1.0, 0.8, 0.6}; // Example link lengths
JointAngles angles = {1.0, 0.5, 0.3};   // Example joint angles
EndEffectorPosition position = calculateForwardKinematics(lengths, angles);
// position.x, position.y, and position.z now contain the computed coordinates of the end effector
```

