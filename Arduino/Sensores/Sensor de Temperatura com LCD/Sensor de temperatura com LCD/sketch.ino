#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 3     
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");

  delay(2000);
}
