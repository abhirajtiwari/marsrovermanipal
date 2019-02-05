int trig2 = 4; //2 is left 1 is right
int trig1 = 5;
int echo2 = 2;
int echo1 = 3;
int mlf = 10;
int mlb = 11;
int mrf = 8;
int mrb = 9;

int long pulseRead(int pin, boolean value) {
  while(digitalRead(pin) == !value);
  int long t1 = micros();
  while(digitalRead(pin) == value);
  int long t2 = micros();
  return t2-t1;
}

void trigger(int pin) {
  digitalWrite(pin, LOW);
  delayMicroseconds(5);
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
}

void right() {
  digitalWrite(mlf, HIGH);
  digitalWrite(mlb, LOW);
  digitalWrite(mrf, LOW);
  digitalWrite(mrb, HIGH);
}

void left() {
  digitalWrite(mlf, LOW);
  digitalWrite(mlb, HIGH);
  digitalWrite(mrf, HIGH);
  digitalWrite(mrb, LOW);
}

void forward() {
  digitalWrite(mlf, HIGH);
  digitalWrite(mlb, LOW);
  digitalWrite(mrf, HIGH);
  digitalWrite(mrb, LOW);
}

void backward() {
  digitalWrite(mlf, LOW);
  digitalWrite(mlb, HIGH);
  digitalWrite(mrf, LOW);
  digitalWrite(mrb, HIGH);
}

void uturn(int mindist, long int distance1, long int distance2) {
  while (distance1 < mindist || distance2 < mindist) {
    backward();
    trigger(trig1);
    distance1 = pulseRead(echo1, HIGH)/58;
    trigger(trig2);
    distance2 = pulseRead(echo2, HIGH)/58;
  }
  left();
}

void setup() {
  pinMode(trig1, OUTPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  pinMode(mlf, OUTPUT);
  pinMode(mlb, OUTPUT);
  pinMode(mrf, OUTPUT);
  pinMode(mrb, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  trigger(trig1);
  long int duration1 = pulseRead(echo1, HIGH);
  long int distance1 = duration1/58;

  trigger(trig2);
  long int duration2 = pulseRead(echo2, HIGH);
  long int distance2 = duration2/58;

  Serial.print(distance2);
  Serial.print(" ");
  Serial.println(distance1);

  int mindist = 20;
  
  if(distance1 < mindist && distance2 > mindist) {
    left();
  }
  else if(distance1 > mindist && distance2 < mindist) {
    right(); 
  }
  else if(distance1 < mindist && distance2 < mindist) {
    uturn(mindist, distance1, distance2);
  }
  else {
    forward();
  }
  
}
