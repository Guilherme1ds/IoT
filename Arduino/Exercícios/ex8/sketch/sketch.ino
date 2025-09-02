int pot = A0;
int n;

void setup() {
  for(int i=4;i<=13;i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  n = analogRead(pot);
  for(int i=4;i<=13;i++){
    if(i < 4+n) digitalWrite(i, HIGH);
    else digitalWrite(i, LOW);
  }
}
