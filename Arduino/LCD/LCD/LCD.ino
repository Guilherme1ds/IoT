#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int backlightPin = 13;

void setup() {
  lcd.begin(16, 2);

  pinMode(backlightPin, OUTPUT);

  digitalWrite(backlightPin, HIGH);

  lcd.setCursor(0, 0);
  lcd.print("Ola, mundo!");
  
  lcd.setCursor(0, 1);
  lcd.print("Oi Bruno!");
}

void loop() {
  // Nada no loop, pois a mensagem é exibida apenas uma vez no setup
}
