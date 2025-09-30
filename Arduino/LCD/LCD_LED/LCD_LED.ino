#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int ledVermelho = 10;
int ledAmarelo  = 9;
int ledVerde    = 8;

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Sistema Iniciado");
  delay(2000);
  lcd.clear();
}

void loop() {
  digitalWrite(ledVerde, HIGH);
  lcd.setCursor(0,0);
  lcd.print("Verde ligado!   ");
  delay(2000);
  digitalWrite(ledVerde, LOW);

  digitalWrite(ledAmarelo, HIGH);
  lcd.setCursor(0,0);
  lcd.print("Amarelo ligado! ");
  delay(2000);
  digitalWrite(ledAmarelo, LOW);

  digitalWrite(ledVermelho, HIGH);
  lcd.setCursor(0,0);
  lcd.print("Vermelho ligado!");
  delay(2000);
  digitalWrite(ledVermelho, LOW);
}
