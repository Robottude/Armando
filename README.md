# Armando

**Armando is a functional, easy-to-use library for Robot Arm control. Supports ESP32 and various Arduino boards. Includes Kinematic parameters analysis and hardware control.**

Contains Inverse and Forward Kinematics calculation functions, workspace bounds calculation, and servo control for 3-DOF Robot Arms with all revolute joints, and user-configurable link lengths.

Due to preprocessor directives that allow both ESP32 and Arduino compatibility, when using an ESP32 board, 'ESP32' should be defined when compiling, either through IDE or build system.

### Robot structure

Kinematics equations are based on the following DH parameters which indicate the Robot's configuration:

**All-zero link offsets: d1=0, d2=0, and d3=0;**

**Arbitrary (user-configurable) link lengths: a1, a2, and a3;**

**Link twists: alpha1=0, alpha2=pi/2, and alpha3=0;**

And as such should be considered when building the Robot Arm hardware.
