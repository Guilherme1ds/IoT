#include <LiquidCrystal.h>

const int ledPin = 13; 
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.print("Fechada"); 
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 'A') { 
      digitalWrite(ledPin, HIGH);
      lcd.clear();
      lcd.print("Aberta");
    } else if (command == 'a') { 
      digitalWrite(ledPin, LOW);
      lcd.clear();
      lcd.print("Fechada");
    }
  }
}
