// Include the Servo library
#include <Servo.h>
// Declare the Servo pin
int hip_joint_pin = 8;
int knee_joint_pin = 9;
int foot_joint_pin = 10;
// Create a servo object
Servo hip_joint;
Servo knee_joint;
Servo foot_joint;
void setup()
{
    // We need to attach the servo to the used pin number
    hip_joint.attach(hip_joint_pin);
    knee_joint.attach(knee_joint_pin);
    foot_joint.attach(foot_joint_pin);
    
    Serial.begin(9600);
    Serial.println("ANNOUNCE leg1");
    
    hip_joint.write(90);
    moveServo(knee_joint, -20, 0);
    moveServo(foot_joint, -20, 0);
}
void loop()
{
    String message = Serial.readStringUntil('\n');
    if (message.length() == 0)
    {
        return;
    }
    Serial.print(message);
    Serial.print(" -> ");
    if (message.equals("move up"))
    {
      Serial.println("Moving knee up");
      moveServo(knee_joint, 60, 0);
      Serial.println("Moving foot up");
      moveServo(foot_joint, 60, 0);

    }
    else if (message.equals("move down"))
    {
      Serial.println("Moving knee down");
      moveServo(knee_joint, -20, 0);
      Serial.println("Moving foot down");
      moveServo(foot_joint, -20, 0);

    }
    else if (message.startsWith("rotate "))
    {
      //  rotate 90 -> the 9 has index 7
      int degrees = message.substring(7).toInt();
      Serial.println("moving to " + String(degrees) + " degrees");
      moveServo(hip_joint, degrees, 0);      
    }
    else
    {
        Serial.println("Action not implemented");
        return;
    }
}
int moveServo(Servo servo, int pos, int delay)
{
    pos = (pos + 60) * (180 / 120);
    // +60 to convert [-60, 60] to [0 - 120]
    // *(180/120) to convert [0, 120] to [0, 180]
    servo.write(pos);
}
