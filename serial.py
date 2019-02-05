import serial

ser = serial.Serial('/dev/ttyACM0', 9600)

pwm = 255
ser.write(bytes(pwm))
'''
other statements are ser.read(datasize), ser.in_waiting()
'''
