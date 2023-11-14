// InverseKinematics.h
#ifndef INVERSE_KINEMATICS_H
#define INVERSE_KINEMATICS_H

#include "RobotArmConfig.h"
#include <math.h>

JointAngles calculateInverseKinematics(const LinkLengths& linkLengths, const EndEffectorPosition& position);

#endif