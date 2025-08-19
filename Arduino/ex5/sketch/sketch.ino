void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  int potencia = analogRead(A0);
  int brilho = map(potencia, 0, 1023, 0, 255);
  analogWrite(13, brilho);
  delay(10);
}
