import RPi.GPIO as gpio
import time

gpio.setmode(gpio.BCM)

echo = 18
trig = 16

gpio.setup(echo, gpio.IN)
gpio.setup(trig, gpio.OUT)

def trigger(pin):
    gpio.output(pin, gpio.LOW)
    # time.sleep(5e-6) #time to clean up for the ultrasonic sensor
    time.sleep(0.2)
    gpio.output(pin, gpio.HIGH) # TIMING????
    time.sleep(1e-5)
    gpio.output(pin, gpio.LOW)

def pulseRead(pin, level):
    while gpio.input(pin) != level:
        pass
    t1 = round(time.time() * 1e6)
    while gpio.input(pin) ==  level:
        pass
    t2 = round(time.time() * 1e6)
    return t2-t1

try:
    while True:
        trigger(trig)
        duration = pulseRead(echo, gpio.HIGH)

        distance = duration/58
        print distance

except KeyboardInterrupt:
    pass

gpio.cleanup()
print 'Done'

    

