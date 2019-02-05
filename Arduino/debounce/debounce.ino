boolean debounce(boolean last, int pin) {
  bool current = digitalRead(pin);
  if(current != last) {
    delay(10);
    current = digitalRead(pin);
  }
  return current;
}
// use the debouce function to read the value of a switch 


void setup() {
  pinMode(8, OUTPUT);
  pinMode(3, INPUT);
  digitalWrite(3,HIGH);

}
boolean glast = LOW;
boolean led = false;
boolean currentButton = LOW;

void loop() {
  currentButton = debounce(glast, 3);
  if(currentButton == LOW && glast == HIGH) {
    led = !led;
  }
  digitalWrite(8, led);
  glast = currentButton;
}
