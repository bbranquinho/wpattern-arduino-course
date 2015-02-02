int pinoLed = 2;
int pinoLdr = 0;

int ldr = 0;
int pwm = 0;

void setup()  {
  pinMode(pinoLed, OUTPUT);
}

void loop() {
  ldr = analogRead(pinoLdr);
  pwm = map(ldr, 0, 1023, 0, 255);
  analogWrite(pinoLed, pwm);
  delay(30);
}

