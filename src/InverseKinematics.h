// InverseKinematics.h
#ifndef INVERSE_KINEMATICS_H
#define INVERSE_KINEMATICS_H

#include "RobotArmConfig.h"

class InverseKinematics {
public:
  InverseKinematics(const RobotArmConfig& config);
  bool calculateInverseKinematics(float end_effector_position[3], float joint_angles[3]);
private:
  RobotArmConfig arm_config;
};

#endif