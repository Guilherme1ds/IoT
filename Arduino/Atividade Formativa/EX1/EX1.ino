#include "DHT.h"

DHT dht(3, DHT11);  
#define LED_VERDE 13
#define LED_AMARELO 12
#define LED_VERMELHO 11

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
}

void loop() {
  delay(2000);
  float temperatura = dht.readTemperature();

  if (isnan(temperatura)) {
    Serial.println("ERRO NO SENSOR!");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  digitalWrite(LED_VERDE, temperatura < 25);
  digitalWrite(LED_AMARELO, temperatura >= 25 && temperatura < 30);
  digitalWrite(LED_VERMELHO, temperatura >= 30);
}
