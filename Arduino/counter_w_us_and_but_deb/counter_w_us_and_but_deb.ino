int trig = 3;
int echo = 2;
int l[3] = {8,9,10};
int b[2] = {4,5};
int bin[3] = {0};
int counter = 0;

boolean debounce(boolean last, int pin) {
  bool current = digitalRead(pin);
  if(current != last) {
    delay(10);
    current = digitalRead(pin);
  }
  return current;
}

void toBinary(int num) {
  for (int i = 0; i < 3; ++i) bin[i]=0;
  for (int i = 0; num!=0 && i < 3; ++i) {
    bin[i] = num%2;
    num/=2;
  }
}

void show() {
  for(int i = 0; i<3; ++i) digitalWrite(l[i], LOW);
  for(int i = 0; i<3; ++i) {
    if(bin[i] == 1) digitalWrite(l[i], HIGH);
  }
}

int long pulseRead(int pin, boolean value) {
  int long t1 = micros();
  while(digitalRead(pin) == value);
  int long t2 = micros();
  return t2-t1;
}

void setup() {
  pinMode(l[0],OUTPUT);
  pinMode(l[1], OUTPUT);
  pinMode(l[2], OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

  pinMode(b[0], INPUT);
  pinMode(b[1], INPUT);
  digitalWrite(b[0], HIGH);
  digitalWrite(b[1], HIGH);
  Serial.begin(9600);

}

void usMode(){
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  while(digitalRead(echo) == LOW);
  
  int long duration;
  duration = pulseRead(echo,HIGH);

  int long distance;
  distance = (duration/58); //cm
  toBinary(map(distance, 0, 100, 0, 7));
  show();
}

boolean currentButton = LOW;
boolean glast = LOW;
boolean currentButton2 = LOW;
boolean glast2 = LOW;

void butMode() {
  currentButton2 = debounce(glast2, b[0]);
    if(currentButton == LOW && glast2 == HIGH) {
    if (counter == 7) counter=0;
    else counter++;
  }
  //Serial.print(counter);
  toBinary(counter);
  show(); 
  glast2 = currentButton2;
}

boolean bmode = true; //true for button and false for arduino
  
void loop() {
  currentButton = debounce(glast, b[1]);
  if(currentButton == LOW && glast == HIGH) bmode = (!bmode);
  if(bmode) butMode();
  else usMode(); 
  Serial.print(bmode);
  glast = currentButton;
  //delay(125);
}
