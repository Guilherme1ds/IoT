#define PINO_LDR A0  

int valorLuz = 0;  

void setup() {
  Serial.begin(9600);  
}

void loop() {
  valorLuz = analogRead(PINO_LDR);

  Serial.print("Nivel de Luz: ");
  Serial.println(valorLuz);

  delay(500);
}
