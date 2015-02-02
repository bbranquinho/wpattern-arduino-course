int pinoSensor = 0;

int pinoBuzzer = 6;
int pinoLed1 = 8;
int pinoLed2 = 9;
int pinoLed3 = 10;
int pinoLed4 = 11;
int pinoLed5 = 12;
int pinoLed6 = 13;

int valorSensor = 0;

void setup(){
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoLed1, OUTPUT);
  pinMode(pinoLed2, OUTPUT);
  pinMode(pinoLed3, OUTPUT);
  pinMode(pinoLed4, OUTPUT);
  pinMode(pinoLed5, OUTPUT);
  pinMode(pinoLed6, OUTPUT);
  
  Serial.begin(9600);
}

void loop(){
  valorSensor = analogRead(pinoSensor);
  Serial.print("Valor do Sensor = ");
  Serial.println(valorSensor);
  
  if (valorSensor > 0){
    digitalWrite(pinoLed1, HIGH);
  } else {
    digitalWrite(pinoLed1, LOW);
  }
  
  if (valorSensor > 915){
    digitalWrite(pinoLed2, HIGH);
  } else {
    digitalWrite(pinoLed2, LOW);
  }
  
  if (valorSensor > 920){
    digitalWrite(pinoLed3, HIGH);
  } else {
    digitalWrite(pinoLed3, LOW);
  }
  
  if (valorSensor > 930){
    digitalWrite(pinoLed4, HIGH);
  } else {
    digitalWrite(pinoLed4, LOW);
  }
  
  if (valorSensor > 935){
    digitalWrite(pinoLed5, HIGH);
  } else {
    digitalWrite(pinoLed5, LOW);
  }
  
  if (valorSensor > 940){
    digitalWrite(pinoLed6, HIGH);
    digitalWrite(pinoBuzzer, HIGH);
  } else {
    digitalWrite(pinoLed6, LOW);
    digitalWrite(pinoBuzzer, LOW);
  }
}

