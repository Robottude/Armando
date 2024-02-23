#include "Armando.h"

  Motor Servos(3,5,6);
  int angle[]  = { 45, 45, 45 };   //ANGLE  MOTOR {1, 2, 3}
  Moves moves;

void setup() {
    //SETUP INPUTS
    pinMode(0,INPUT);  //0,1 for L,R  2,4 for UP,DOWN
    pinMode(1,INPUT);
    pinMode(2,INPUT);   // 3 IN USE FOR SERVOS
    pinMode(4,INPUT);
    //
    Servos.initialize();
    Servos.moveJoints(angle[0],angle[1],angle[2]);     
    Serial.begin(115200);
    delay(10);
    

}

void loop() {
  // put your main code here, to run repeatedly:
  bool ispressed = false;
  if(digitalRead(0)==HIGH && ispressed == false){
    ispressed = true;
    moves =  MOVE_LEFT;
    Servos.moveJoystick(moves,angle);
  }

  if(digitalRead(1)==HIGH && ispressed == false){
    ispressed = true;
    moves =  MOVE_RIGHT;
    Servos.moveJoystick(moves,angle);
    
  }

  if(digitalRead(2)==HIGH && ispressed == false){
    ispressed = true;
    moves =  MOVE_UP;
    Servos.moveJoystick(moves,angle);
  }

  if(digitalRead(0)==HIGH && ispressed == false){
    ispressed = true;
    moves =  MOVE_DOWN;
    Servos.moveJoystick(moves,angle);
  }
  
  
  
  
}
