// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 8; 
// Create a servo object 
Servo Servo1; 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin);
   Serial.begin(9600); 
   Serial.println("ANNOUNCE servo_with_message5");
   Servo1.write(0); 
}
void loop(){ 
  String message = Serial.readStringUntil("\n");
  if (message.length() == 0) {
    return;
  }
  Serial.print(message); 
  Serial.print(" -> ");
  if (!message.startsWith("move ")){
    Serial.println("not implemented");
    return;
  }
  //  move 90 -> the 9 has index 5
  int degrees = message.substring(5).toInt();
  Serial.println("moving to " + String(degrees) + " degrees");
  Servo1.write(degrees); 
}
