// ForwardKinematics.h
#ifndef FORWARD_KINEMATICS_H
#define FORWARD_KINEMATICS_H

#include "RobotArmConfig.h"

EndEffectorPosition calculateForwardKinematics(const LinkLengths& linkLengths, const JointAngles& angles);

#endif