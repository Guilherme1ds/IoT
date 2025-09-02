int led = 9;

void setup(){
  pinMode(led, OUTPUT);
}

void loop(){
  // S = "..."
  digitalWrite(led,HIGH); delay(250); digitalWrite(led,LOW); delay(250);
  digitalWrite(led,HIGH); delay(250); digitalWrite(led,LOW); delay(250);
  digitalWrite(led,HIGH); delay(250); digitalWrite(led,LOW); delay(500);

  // O = "---"
  digitalWrite(led,HIGH); delay(750); digitalWrite(led,LOW); delay(250);
  digitalWrite(led,HIGH); delay(750); digitalWrite(led,LOW); delay(250);
  digitalWrite(led,HIGH); delay(750); digitalWrite(led,LOW); delay(500);

  // S = "..."
  digitalWrite(led,HIGH); delay(250); digitalWrite(led,LOW); delay(250);
  digitalWrite(led,HIGH); delay(250); digitalWrite(led,LOW); delay(250);
  digitalWrite(led,HIGH); delay(250); digitalWrite(led,LOW); delay(2000); // pausa antes de repetir
}
