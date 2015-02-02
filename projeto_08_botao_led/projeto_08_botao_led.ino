int pinoLed = 6;
int pinoBotao = 7;
int valorBotao;

void setup() {
  pinMode(pinoLed, OUTPUT);
  pinMode(pinoBotao, INPUT);
}

void loop(){
  valorBotao = digitalRead(pinoBotao);
  
  if (valorBotao == HIGH) {
    digitalWrite(pinoLed, LOW);
  } else {
    digitalWrite(pinoLed, HIGH);
  }
}


