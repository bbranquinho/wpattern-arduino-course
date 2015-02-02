#include <Servo.h> 
 
Servo servo;
int pos = 0;
String input = "";
 
void setup() 
{
  Serial.begin(9600);
  servo.attach(9);
} 

void loop() 
{
  if (Serial.available() > 0) { 
    while (Serial.available() > 0) {
      char inputRead = (char)Serial.read();
      
      if (inputRead == ':') {
        int angle = atoi(input.c_str());
        
        servo.write(angle);
        input = "";
      } else {
        input = input + inputRead;
      }
    }
  }
}

