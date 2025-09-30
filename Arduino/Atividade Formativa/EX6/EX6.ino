// #include <Wire.h>
#include <LiquidCrystal.h>

// Endereço do módulo I2C (0x27 é o mais comum, mas pode ser 0x3F)
LiquidCrystal lcd(0x27, 16, 2);

void setup() {
  // Inicializa o LCD
  lcd.init();
  // Acende a luz de fundo
  lcd.backlight();
  // Posiciona o cursor na primeira coluna, primeira linha
  lcd.setCursor(0, 0);
  // Exibe a primeira mensagem
  lcd.print("Ola, mundo!");
  // Posiciona o cursor na primeira coluna, segunda linha
  lcd.setCursor(0, 1);
  // Exibe a segunda mensagem
  lcd.print("Oi Bruno!");
}

void loop() {
  // Nada no loop, pois a mensagem é exibida apenas uma vez no setup
}
