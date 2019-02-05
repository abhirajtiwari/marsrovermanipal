int trig = 4;
int echo = 2;

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

int long pulseRead(int pin, boolean value) {
  while(digitalRead(echo) == LOW);
  int long t1 = micros();
  while(digitalRead(pin) == value);
  int long t2 = micros();
  return t2-t1;
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  int long duration;
  duration = pulseRead(echo,HIGH);

  int long distance;
  distance = (duration/58); //cm
  Serial.print(distance);
  Serial.print("\n");
  delay(1000);

}
