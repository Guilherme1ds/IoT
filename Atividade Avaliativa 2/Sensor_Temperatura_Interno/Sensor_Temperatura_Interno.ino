#include "DHT.h"
#include <LiquidCrystal.h> 

#define DHTPIN 2        
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

const int ledPinVerde = 7;
const int ledPinVermelho   = 8;
const int buzzerPin = 9; 

LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

float limiteAlto  = 30.0;  
float limiteBaixo = 18.0; 

unsigned long lastRead = 0;
const unsigned long readInterval = 2000; 

void setup() {
  Serial.begin(9600);

  dht.begin();

  pinMode(ledPinVerde, OUTPUT);
  pinMode(ledPinVermelho, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Monitor Temp");
  delay(1500);
  lcd.clear();
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    switch (command) {
      case 'A':
        digitalWrite(ledPinVerde, HIGH);
        break;
      case 'a':
        digitalWrite(ledPinVerde, LOW);
        break;
      case 'B':
        digitalWrite(ledPinVermelho, HIGH);
        break;
      case 'b':
        digitalWrite(ledPinVermelho, LOW);
        break;
      case 'T':
        sendTempHumidOnce();
        break;
      default:
        break;
    }
  }

  if (millis() - lastRead >= readInterval) {
    lastRead = millis();
    readAndHandleSensor();
  }
}

void readAndHandleSensor() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(t) || isnan(h)) {
    lcd.clear();
    lcd.print("Erro sensor!");
    Serial.println("ERRO");
    digitalWrite(ledPinVerde, LOW);
    digitalWrite(ledPinVermelho, LOW);
    noTone(buzzerPin);
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(t, 1); 
  lcd.print("C   "); 

  lcd.setCursor(0, 1);
  lcd.print("Umid:");
  lcd.print(h, 1);
  lcd.print("%    ");

  Serial.print(t, 2);
  Serial.print(";");
  Serial.println(h, 2);

  if (t > limiteAlto) {
    digitalWrite(ledPinVermelho, HIGH);   
    digitalWrite(ledPinVerde, LOW);
    tone(buzzerPin, 2000); 
  } else if (t < limiteBaixo) {
    digitalWrite(ledPinVerde, HIGH); 
    digitalWrite(ledPinVermelho, LOW);
    noTone(buzzerPin); 
  } else {
    digitalWrite(ledPinVerde, LOW);
    digitalWrite(ledPinVermelho, LOW);
    noTone(buzzerPin); 
  }
}

void sendTempHumidOnce() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(t) || isnan(h)) {
    Serial.println("ERRO");
    return;
  }

  Serial.print(t, 2);
  Serial.print(";");
  Serial.println(h, 2);
}
