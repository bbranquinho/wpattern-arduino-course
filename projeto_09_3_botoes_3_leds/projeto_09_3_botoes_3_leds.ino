int pinoLed1 = 2;
int pinoBotao1 = 3;
int pinoLed2 = 4;
int pinoBotao2 = 5;
int pinoLed3 = 6;
int pinoBotao3 = 7;

int valorBotao1;
int valorBotao2;
int valorBotao3;

void setup() {
  pinMode(pinoLed1, OUTPUT);
  pinMode(pinoBotao1, INPUT);
  pinMode(pinoLed2, OUTPUT);
  pinMode(pinoBotao2, INPUT);
  pinMode(pinoLed3, OUTPUT);
  pinMode(pinoBotao3, INPUT);
}

void loop(){
  valorBotao1 = digitalRead(pinoBotao1);
  if (valorBotao1 == HIGH) {
    digitalWrite(pinoLed1, LOW);
  } else {
    digitalWrite(pinoLed1, HIGH);
  }
  
  valorBotao2 = digitalRead(pinoBotao2);
  if (valorBotao2 == HIGH) {
    digitalWrite(pinoLed2, LOW);
  } else {
    digitalWrite(pinoLed2, HIGH);
  }
  
  valorBotao3 = digitalRead(pinoBotao3);
  if (valorBotao3 == HIGH) {
    digitalWrite(pinoLed3, LOW);
  } else {
    digitalWrite(pinoLed3, HIGH);
  }
}


