#!/usr/bin/env python
import time
import serial

ser = serial.Serial('/dev/ttyUSB0', 9600)
#while True :
#        state=ser.readline()
#        print(state)

while 1:
      distance1=ord(ser.read())
      distance2=ord(ser.read())
      distance3=ord(ser.read())
      distance4=ord(ser.read())
      print distance1, distance2, distance3, distance4
