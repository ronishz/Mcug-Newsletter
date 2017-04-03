import Adafruit_BBIO.GPIO as GPIO
import time

#declare phase
segment = ['P8_11','P8_12','P8_13','P8_14','P8_15','P8_16','P8_17']
zero = ['P8_11','P8_12','P8_13','P8_14','P8_15','P8_16']
one = ['P8_12','P8_13']
two = ['P8_11','P8_12','P8_14','P8_15','P8_17']
three = ['P8_11','P8_12','P8_13','P8_14','P8_17']
upLED = ['P9_11','P9_13','P9_15','P9_24']
downLED = ['P9_12','P9_14','P9_16','P9_23']
switch = ['P8_10','P8_8','P8_9','P8_7']

#setup phase
for i in range(len(segment)):
        GPIO.setup(segment[i],GPIO.OUT)
for i in range(len(upLED)):
        GPIO.setup(upLED[i],GPIO.OUT)
        GPIO.setup(downLED[i],GPIO.OUT)
        GPIO.setup(switch[i],GPIO.IN)

#initialize phase
for i in range(len(segment)):
        GPIO.output(segment[i],GPIO.HIGH)
for i in range(len(upLED)):
        GPIO.output(upLED[i],GPIO.LOW)
        GPIO.output(downLED[i],GPIO.LOW)
                                        
#functions
def disp(x):
        for i in range(len(segment)):
                GPIO.output(segment[i],GPIO.HIGH)
        if(x==0):
                for i in range(len(zero)):
                        GPIO.output(zero[i],GPIO.LOW)     
        elif(x==1):
                for i in range(len(one)):
                        GPIO.output(one[i],GPIO.LOW)     
        elif(x==2):
                for i in range(len(two)):
                        GPIO.output(two[i],GPIO.LOW)     
        elif(x==3):
                for i in range(len(three)):
                        GPIO.output(three[i],GPIO.LOW)     

#working                                                                        
current=0
destination=0
def display(current,destination):
        if(current<destination):
                for i in range(len(upLED)):
                        GPIO.output(upLED[i],GPIO.HIGH)
                        GPIO.output(downLED[i],GPIO.LOW)
                for i in range(current,destination+1):
                        disp(i)
                        time.sleep(2)
		for i in range(len(upLED)):
			GPIO.output(upLED[i],GPIO.LOW)
        elif(current>destination):
                for i in range(len(downLED)):
                        GPIO.output(downLED[i],GPIO.HIGH)
                        GPIO.output(upLED[i],GPIO.LOW)
                for i in range(current,destination-1,-1):
                        disp(i)
                        time.sleep(2)
		for i in range(len(downLED)):
			GPIO.output(downLED[i],GPIO.LOW)
while True:
        if(GPIO.input("P8_7")==0):
                current=destination
                destination=3
                display(current,destination)
        elif(GPIO.input("P8_9")==0):
                current=destination
                destination=2
                display(current,destination)
        elif(GPIO.input("P8_8")==0):
                current=destination
                destination=1
                display(current,destination)
        elif(GPIO.input("P8_10")==0):
                current=destination
                destination=0
                display(current,destination)

