int pinoPotenciometro = 0;
int pinoLed = 0;
int valor = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinoLed, OUTPUT);
}

void loop() {
  valor = analogRead(pinoPotenciometro);
  Serial.print("Valor do potenciometro: ");
  Serial.println(valor);
  digitalWrite(pinoLed, HIGH);
  delay(valor);
  digitalWrite(pinoLed, LOW);
  delay(valor);
}


