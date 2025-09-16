#define LED_VERMELHO 2
#define LED_AMARELO 3
#define LED_VERDE 4
#define LED_PEDESTRE 5
#define BOTAO 6

void setup() {
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_PEDESTRE, OUTPUT);

  pinMode(BOTAO, INPUT_PULLUP);
}

void loop() {
  digitalWrite(LED_VERDE, HIGH);
  delay(3000);
  digitalWrite(LED_VERDE, LOW);

  digitalWrite(LED_AMARELO, HIGH);
  delay(1000);
  digitalWrite(LED_AMARELO, LOW);

  digitalWrite(LED_VERMELHO, HIGH);
  delay(3000);

  if (digitalRead(BOTAO) == LOW) {
    digitalWrite(LED_PEDESTRE, HIGH);
    delay(3000);
    digitalWrite(LED_PEDESTRE, LOW);
  }

  digitalWrite(LED_VERMELHO, LOW);
}
