// ForwardKinematics.h
#ifndef FORWARD_KINEMATICS_H
#define FORWARD_KINEMATICS_H

#include "RobotArmConfig.h"

class ForwardKinematics {
public:
  ForwardKinematics(const RobotArmConfig& config);
  void calculateForwardKinematics(float joint_angles[3], float end_effector_position[3]);
private:
  RobotArmConfig arm_config;
};

#endif