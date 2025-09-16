#include <Servo.h>

Servo servo;         
int potPin = A0;     
int valorPot;        
int angulo;          

void setup() {
  servo.attach(9);   
}

void loop() {
  valorPot = analogRead(potPin);           
  angulo = map(valorPot, 0, 1023, 0, 180); 
  servo.write(angulo);                     
  delay(15);                               
}