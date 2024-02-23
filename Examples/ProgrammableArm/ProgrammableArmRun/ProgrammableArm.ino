//In this example Robot arm will run predefined program in ControlRobotArm header file
//In header we will have defined program witch is represented as a structure {angle1,angle2,angle3,delay},
//Writing of this file currently is only posible manually
     
#include "Armando.h"
  //GLOBAL VARIABLE
  Motor Servos(3,5,6);
  int angle[]  = { 0, 90, 0 };   //ANGLE  MOTOR {1, 2, 3}
  uint16_t sizeOfProgram = arrSize(program), counter = 0x0000;
//Functions
  void WriteToSerial(uint16_t del){
  Serial.write("********************************************************************\n\n");
  Serial.write("\t\t\tRobottude lib\n");
  Serial.write("Move to:\n");
  Serial.write("\nMove to:\n");
  Serial.write("\nangle1: ");
  Serial.write(angle[0]);   
  Serial.write("\nangle2: ");
  Serial.write(angle[1]);
  Serial.write("\nangle3: ");
  Serial.write(angle[2]);
  Serial.write("delay: ");
  Serial.write(del);  
  Serial.write("********************************************************************\n");
}
//
void setup() {
 
    Servos.initialize();
    Serial.begin(115200);
    Servos.moveJoints(angle[0],angle[1],angle[2]);
    delay(50);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  angle[0] = program[counter].angle1;
  angle[1] = program[counter].angle2;
  angle[2] = program[counter].angle3;
  uint16_t del = program[counter].del;
  
  
  Servos.moveJoints(angle[0],angle[1],angle[2]);
  WriteToSerial(del);
  delay(del);
  counter++;
  if(counter == sizeOfProgram)
    counter=0x0000;
  
}
