#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int pinoLed = 0;
int pinoBotao = 1;
int valorBotao;

void setup(){
  pinMode(pinoLed, OUTPUT);
  pinMode(pinoBotao, INPUT);
  
  lcd.begin(16, 2);
}

void loop()
{
  valorBotao = digitalRead(pinoBotao);
  
  lcd.clear();
  
  if (valorBotao == HIGH) {
    digitalWrite(pinoLed, LOW);
    lcd.write("DESLIGADO");
  } else {
    digitalWrite(pinoLed, HIGH);
    lcd.write("LIGADO");
  }
  
  delay(30);
}


