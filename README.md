# Armed

Functional, easy-to-use library for Robot Arm control. Includes Kinematic parameters analysis and hardware control.

Includes Kinematics calculation functions and motor control for 3-DOF Robot Arms with all revolute joints, and user-configurable link lengths.

Kinematics equations are based on the following DH parameters which indicates Robot's configuration:

**All-zero link offsets: d1=0, d2=0, and d3=0;**

**Arbitrary (user-configurable) link lengths: a1, a2, and a3;**

**Link twists: alpha1=0, alpha2=pi/2, and alpha3=0;**

And as such should be considered when building the Robot Arm hardware.