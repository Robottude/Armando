// RobotArmConfig.h
#ifndef ROBOT_ARM_CONFIG_H
#define ROBOT_ARM_CONFIG_H

struct RobotArmConfig {
  float link_lengths[3];
  float offsets[3];
  // other dh parameters if needed
};

#endif