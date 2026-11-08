#include <Servo.h>
#define button 7

int pos = 0;

Servo servo_9;

void setup()
{
  pinMode(button, INPUT);
  servo_9.attach(9, 500, 2500);

  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(button) == HIGH) {
   pos = 180;
   servo_9.write(pos);
   Serial.println("pressed");
 }
  else {
    pos = 0;
    servo_9.write(pos);
  }
}
