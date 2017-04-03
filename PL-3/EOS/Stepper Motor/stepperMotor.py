#full sequence
import Adafruit_BBIO.GPIO as GPIO
import time
stator=['P9_11','P9_12','P9_13','P9_14']

#setup
for i in range(len(stator)):
        GPIO.setup(stator[i],GPIO.OUT)
        GPIO.output(stator[i],GPIO.LOW)

while True:
        for i in range(len(stator)):
                GPIO.output(stator[i],GPIO.HIGH)
                time.sleep(1)
                GPIO.output(stator[i],GPIO.LOW)


#half sequence
import Adafruit_BBIO.GPIO as GPIO
import time
stator=['P9_11','P9_12','P9_13','P9_14']

#setup
for i in range(len(stator)):
        GPIO.setup(stator[i],GPIO.OUT)
        GPIO.output(stator[i],GPIO.LOW)
while True:
        for i in range(len(stator)):
                j=i+1
                if(j==4):
                        j=0
                GPIO.output(stator[i],GPIO.HIGH)
                time.sleep(0.1)
                GPIO.output(stator[j],GPIO.HIGH)
                time.sleep(0.1)
                GPIO.output(stator[i],GPIO.LOW)

