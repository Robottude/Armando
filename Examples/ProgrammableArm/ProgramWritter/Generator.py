# -*- coding: utf-8 -*-
"""
Created on Mon Nov 27 10:34:48 2023

@author: BLAGI
"""

import serial
import os





file = open("ControlRobotArm.h","w")
structure = '#define arrSize(x) sizeof(x) / sizeof(x[0])/ntypedef struct PROGRAM{/nuint8_t  angle1;/nuint8_t  angle2;/nuint8_t  angle3; /nuint16_t del;/n}PROGRAM;\nPROGRAM program[]={'
file.write(structure)

ser = serial.Serial('COM3') # if Linux '/dev/ttyUSB0'
ser.baudrate = 115200 
end = False
print("press q for QUIT")
while (end==False):
    if(ser.out_waiting == 3):
        angles = ser.read(3)  #read 3 angle
        print("\nWe Received Angles %d ,%d ,%d", angles[0], angles[1], angles[2])
        print("\nInput Delay (ms) : ")
        
        delay = input()
        if(delay== 'q' or delay== 'Q'):
            break
        L = ['\n{',angles[0].toString(),',',angles[1].toString(),',',angles[2].toString(),',',delay,'},']
        file.writelines(L)
        ser.reset_output_buffer()
    #M Err


file.write('}')
file.close()
