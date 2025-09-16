int pinoPIR = 2;       
int pinoLED = 3;       
int contador = 0;      
bool movimentoAnterior = LOW; 

void setup() {
  pinMode(pinoPIR, INPUT);
  pinMode(pinoLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int movimento = digitalRead(pinoPIR);

  if (movimento == HIGH && movimentoAnterior == LOW) {
    contador++;
    Serial.print("Pessoas detectadas: ");
    Serial.println(contador);
    digitalWrite(pinoLED, HIGH);
    delay(500); 
  } else {
    digitalWrite(pinoLED, LOW);
  }

  movimentoAnterior = movimento;
}
