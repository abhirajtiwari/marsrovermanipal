int l[3] = {8,9,10};
int b[2] = {3,4};
int bin[3] = {0};
int counter = 0;

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

void setup() {
  pinMode(l[0],OUTPUT);
  pinMode(l[1], OUTPUT);
  pinMode(l[2], OUTPUT);

  pinMode(b[0], INPUT);
  pinMode(b[1], INPUT);
  digitalWrite(b[0], HIGH);
  digitalWrite(b[1], HIGH);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(b[0]) == LOW) {
    if (counter == 7) counter=0;
    else counter++;
  }
  Serial.print(counter);
  toBinary(counter);
  show(); 
  delay(250);
}
