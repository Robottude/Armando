
// This is an example we will use to make a program in which the robot arm will be able to execute.
// Connect Arduino with a USB cable to a PC.
// On the PC, run the script Generator.py (if serial isn't installed, use "pip install pyserial").
// The button is connected to pin 4; log1 = HIGH.
// Press the button to save the current position.
// In Generator.py, a pop-up will appear to input the delay.
// Input the delay.
// To finish writing the program, press 'q' inside Generator.py.
// Use Ctrl+C to terminate.

 

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
