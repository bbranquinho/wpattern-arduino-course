int pinoPotenciometro = 0;
int valorPotenciometro = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  valorPotenciometro = analogRead(pinoPotenciometro);
  Serial.print("Valor do potenciometro: ");
  Serial.println(valorPotenciometro);
  delay(100);
}


