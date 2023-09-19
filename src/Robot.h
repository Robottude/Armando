// UNIVERSAL ROBOT ARM LIBRARY // ユニバーサルロボットアームライブラリ

#ifndef UNIVERSAL_ROBOT_MANIPULATOR_H
#define UNIVERSAL_ROBOT_MANIPULATOR_H

// DH structure, Robot Structure, Trans Matrix
struct DHParameters {
    double theta;
    double d;
    double a;
    double alpha;
};

struct RobotConfiguration {
    // dof size (configurable?)
};

struct TransformationMatrix {
    double TransMatrix[4][4];
};

// Motor Classes, Robot Classes (Forward&Inverse Kin, TransMat calculate) etc.

class StepperMotor {
private:
    // pins

public:
   // move / set direction
};

class RobotManipulator {
private:
    // fk, ik, and trans matrix calculation

public:
    // move joint / move to position(ik)
};


#endif // UNIVERSAL_ROBOT_MANIPULATOR_H
