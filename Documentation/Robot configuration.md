# File: RobotArmConfig.cpp

## Description:

The RobotArmConfig.cpp file defines global variables and functions for configuring the necessary Robot parameters. These functions facilitate the configuration of robot arm parameters, allowing users to set and retrieve values for link lengths, end effector position, and joint angles as needed.

## Functions:

### Setters:

- `void initializeLinkLengths(const LinkLengths& lengths)`: Sets the link lengths of the robot arm to the specified values.

- `void initializeEndEffectorPosition(const EndEffectorPosition& position)`: Sets the end effector position of the robot arm to the specified coordinates.

- `void initializeJointAngles(const JointAngles& angles)`: Sets the joint angles of the robot arm to the specified values.

### Getters:

- `LinkLengths getLinkLengths()`: Retrieves the current link lengths of the robot arm.

- `EndEffectorPosition getEndEffectorPosition()`: Retrieves the current end effector position of the robot arm.

- `JointAngles getJointAngles()`: Retrieves the current joint angles of the robot arm.

## Example:
```cpp
// initialize link lengths, end effector position, and joint angles
    LinkLengths lengths = {1.0, 0.8, 0.6};
    EndEffectorPosition position = {0.0, 0.0, 0.0};
    JointAngles angles = {0.0, 0.0, 0.0};

    initializeLinkLengths(lengths);
    initializeEndEffectorPosition(position);
    initializeJointAngles(angles);

    // retrieve and use robot parameters
    LinkLengths retrieved_lengths = getLinkLengths();
    EndEffectorPosition retrieved_position = getEndEffectorPosition();
    JointAngles retrieved_angles = getJointAngles();
```
