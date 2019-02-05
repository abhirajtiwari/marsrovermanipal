#include <Servo.h>

Servo servo1;

void setup() {
  servo1.attach(9);
}

void loop() {
  for(int i = 0; i<=180; i+=45){
    servo1.write(i);
    delay(500);
  }
}
