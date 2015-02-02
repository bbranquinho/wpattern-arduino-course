int pinoPotenciometro = 0;
int pinoLed = 3;
int valor = 0;
int pwm = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinoLed, OUTPUT);
}

void loop() {
  valor = analogRead(pinoPotenciometro);
  pwm = map(valor, 0, 1023, 0, 255);
  analogWrite(pinoLed, pwm);
  
  Serial.print("Valor do PWM: ");
  Serial.println(pwm);
}


