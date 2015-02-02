int pinoNtc = 0;

int ntc = 0;

void setup()  {
  Serial.begin(9600);
}

void loop() {
  ntc = analogRead(pinoNtc);
  Serial.println(ntc);
  delay(250);
}

