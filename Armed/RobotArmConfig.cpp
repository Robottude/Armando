// RobotArmConfig.cpp
#include "RobotArmConfig.h"

// global variables for robot parameters
LinkLengths link_lengths;
EndEffectorPosition end_effector_position;
JointAngles joint_angles;

// setters
void initializeLinkLengths(const LinkLengths& lengths) {
    link_lengths = lengths;
}

void initializeEndEffectorPosition(const EndEffectorPosition& position) {
    end_effector_position = position;
}

void initializeJointAngles(const JointAngles& angles) {
    joint_angles = angles;
}

// getters
LinkLengths getLinkLengths() {
    return link_lengths;
}

EndEffectorPosition getEndEffectorPosition() {
    return end_effector_position;
}

JointAngles getJointAngles() {
    return joint_angles;
}
