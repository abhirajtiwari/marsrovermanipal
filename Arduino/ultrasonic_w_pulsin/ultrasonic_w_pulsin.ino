int trig = 8;
int echo = 9;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int long duration;
  duration = pulseIn(echo, HIGH);

  int long distance;
  distance = (duration / 58); //cm

  Serial.print(distance);
  Serial.print("\n");
  delay(1000);


}
