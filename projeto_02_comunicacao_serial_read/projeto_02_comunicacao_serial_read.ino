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
      break;
      
      case 'd':
      case 'D':
        digitalWrite(LED, LOW);
      break;
    }
  }
}


