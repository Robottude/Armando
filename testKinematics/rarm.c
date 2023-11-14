#include<stdio.h>
#include "robot_arm.h"

void Init(LinkLengths *lenghts,EndEffectorPosition *positions,JointAngles *angles)
{
	//Init Lenghts from joint to joint
	lenghts->a1=1.0f;
	lenghts->a2=1.0f;
	lenghts->a3=1.0f;
	
	//
	
}
void rad_deg(JointAngles *angle)
{
	double con = (float)180/(2*3.14);
	angle->theta1 =  angle->theta1 * con;
	angle->theta2 =  angle->theta2 * con;
	angle->theta3 =  angle->theta3 * con;
}
int main()
{
	
	LinkLengths lenghts;
	EndEffectorPosition positions;
	JointAngles angles;
	Init(&lenghts,&positions,&angles);
	
	//Input positions
	angles.theta1=0;
	angles.theta2=0;
	angles.theta3=0;
	positions.x = 1;
	positions.y = 1;
	positions.z = 1;
	
	angles = calculateInverseKinematics(lenghts,positions);
	positions = calculateForwardKinematics(lenghts,angles);
	rad_deg(&angles);
	
	
	printf("theta1: %f deg\ntheta2:  %f deg\ntheta3: %f deg\n",angles.theta1,angles.theta2,angles.theta3);
	printf("x: %f\ny:  %f\nz: %f\n",positions.x,positions.y,positions.z);
	return 0;	
}
