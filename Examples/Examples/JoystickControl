#include "Armed.h"

//THIS IS EXAMPLE WHER WE WILL USE A SMALER REPLIKA OF ROBOT ARM TO CONTROL THE ARM(JOJSTICK)
//IN JOINTS WE WILL HAVE POTENTIOMETERS WITCH WILL BE USED TO REPRESENT THE ANGLE WHICH JOINT NEED TO OCCUPY
//POTENTIOMETERS ARE CONECTED ON PINS A0,A1,A2
//ANGLE OF 
//0 DEGREE REPRESENT 0 V ON PIN (RETURN 0 ) 
//180 DEGREE REPRESENT 5 V ON PIN (RETURN 1023)
//ON PIN 4 IS CONECTED BUTTON 
//IT IS USED TO MOVE ARM IN POSITION
Motor Servos(3,5,6);
float angles[3]={0,0,0};
bool isMoved = false;

void readPotentiometers(void){

angles[0]=(int)(analogRead(A0)*180.0/1023.0);
  delay(10);
 angles[1]=(int)(analogRead(A1)*180.0/1023.0);
  delay(10);
angles[2]=(int)(analogRead(A2)*180.0/1023.0);
  delay(10);
  }

 
void setup() {
  // put your setup code here, to run once:
  pinMode(4,INPUT);
  Servos.initialize();
  readPotentiometers(); 
  delay(10);
  Servos.moveJoints(angles[0],angles[1],angles[3]);
   

}

void loop() {
  // put your main code here, to run repeatedly:
 
  
  if(digitalRead(4) == HIGH){
    if(isMoved==false){
      readPotentiometers();
      delay(10);
      Servos.moveJoints(angles[0],angles[1],angles[3]);
    }
    isMoved==true;
  }

  if((digitalRead(4) == LOW)&&(isMoved == true)){isMoved == false;}
}
