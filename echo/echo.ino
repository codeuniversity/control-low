void setup() {
  Serial.begin(9600); 
  Serial.println("ANNOUNCE echo");
}

void loop() {
  String message = Serial.readStringUntil("\n");
  if (message.length() > 0) {
    Serial.println(message); 
  }
}
