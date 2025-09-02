int vermelho = 9; // pino PWM para vermelho
int verde    = 10; // pino PWM para verde
int azul     = 11; // pino PWM para azul

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
}

void loop() {
  // Vermelho
  analogWrite(vermelho, 255);
  analogWrite(verde, 0);
  analogWrite(azul, 0);
  delay(1000);

  // Verde
  analogWrite(vermelho, 0);
  analogWrite(verde, 255);
  analogWrite(azul, 0);
  delay(1000);

  // Azul
  analogWrite(vermelho, 0);
  analogWrite(verde, 0);
  analogWrite(azul, 255);
  delay(1000);
}
