int pinoLdr = 0;

int ldr = 0;

void setup()  {
  Serial.begin(9600);
}

void loop() {
  ldr = analogRead(pinoLdr);
  Serial.println(ldr);
  delay(250);
}

