void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  for (int n = 0; n < 16; n++) {
    digitalWrite(13, n & 1);
    digitalWrite(12, n >> 1 & 1);
    digitalWrite(11, n >> 2 & 1);
    digitalWrite(10, n >> 3 & 1);
    delay(500);
  }
}
