int bin[3] = {0}; //array to store the binary number
void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(13, OUTPUT);
}

void toBinary(int num) {
  for (int i = 0; i < (sizeof(bin)/sizeof(bin[0])); ++i) bin[i]=0;
  for (int i = 0; num!=0 && i<(sizeof(bin)/sizeof(bin[0])); ++i) {
    bin[i] = num%2;
    num/=2;
  }
}

void show(int j) {
  if(j<=3){
    for(int i = 0; i < (sizeof(bin)/sizeof(bin[0])); ++i)
      digitalWrite(i+2, bin[i]);
  }
  else{
    for(int i = 1; i < 3; ++i)
      digitalWrite(i+1, bin[i]);
  }
}

void alert() {  
  for(int i = 0; i<3; ++i){
    digitalWrite(13, HIGH);
    delay(1000/6);
    digitalWrite(13,LOW);
    delay(1000/6);
  }
}

void loop() {
  alert();
  for(int i = 0; i<=7; ++i){
    toBinary(i);
    show(i);
    delay(500);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    delay(500);
  }
}
