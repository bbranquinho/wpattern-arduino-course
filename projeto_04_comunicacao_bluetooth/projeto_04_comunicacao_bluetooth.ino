int LED = 13;

void setup() {                
  Serial1.begin(9600);
  pinMode(LED, OUTPUT);     
}

void loop() {
  if (Serial1.available() > 0) {
    switch ((char)Serial1.read()) {
      case 'l':
      case 'L':
        digitalWrite(LED, HIGH);  
        Serial1.println("LED Ligado");
      break;
      
      case 'd':
      case 'D':
        digitalWrite(LED, LOW);
	Serial1.println("LED Desligado");
      break;
    }
  }
}


