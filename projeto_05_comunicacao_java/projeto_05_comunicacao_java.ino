int LED = 13;

void setup() {                
  Serial.begin(9600);
  pinMode(LED, OUTPUT);     
}

void loop() {
  if (Serial.available() > 0) {
    switch ((char)Serial.read()) {
      case 'l':
      case 'L':
        digitalWrite(LED, HIGH);  
        Serial.println("LED Ligado");
      break;
      
      case 'd':
      case 'D':
        digitalWrite(LED, LOW);
	Serial.println("LED Desligado");
      break;
    }
  }
}


