//This is example  we will use tomake program witch will Robot arm be able to execute
//Conect arduio with a usb cable witha a pc
//On pc we will run script Generator.py (if serial isnt installed pip install pyserial )
//Button is conected on pin 4 log1 = HIGH  
//To save position press button
//In Generator.py we will see pop up to input delay
//Input delay
//To finish writing program press q inside Generator.py
//Ctrl+c to terminate
 

#include "Armed.h"
  Motor Servos(3,5,6);
  bool isPress = false;
  void setup(){
      Servos.initialize();
      Serial.begin(115200);
      pinMode(4,INPUT);
    }
  void loop(){

     if(digitalRead(4)== HIGH && isPress == false)
      {
        Servos.sendAnglesToSerial();
        isPress = true;
        delay(10); 
      }

    if(digitalRead(4) == LOW)
    {
      isPress = false; 
    }
    
    }
