#!/usr/bin/env python 
#nel componente "two color":  G=ground    R=red   Y=green 
import RPi.GPIO as GPIO 
import time 
GPIO.setmode(GPIO.BOARD)       # condizioni iniziali 
GPIO.setup(11, GPIO.OUT) 
GPIO.setup(13, GPIO.OUT) 
GPIO.output(11, GPIO.LOW) 
GPIO.output(13, GPIO.HIGH) 
try: 
    while True: 
        name = raw_input('Enter a s)witch color ­ ctrl c to  quit): ') 
        if name.upper() == ('S'): 
              if GPIO.input(11)  == 1: 
                   GPIO.output(11, GPIO.LOW) # commuta stato led #11 
              else: 
                   GPIO.output(11, GPIO.HIGH) 
              time.sleep(1) 
              if GPIO.input(13)  == 1: 
                   GPIO.output(13, GPIO.LOW) # commuta stato led #13 
              else: 
                   GPIO.output(13, GPIO.HIGH) 
 
except KeyboardInterrupt: 
