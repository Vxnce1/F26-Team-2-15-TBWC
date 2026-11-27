#define enA 3
#define in1A 4
#define in2A 5
#include <Servo.h>
Servo s;

void setup (){
  Serial.begin(9600);
  s.attach(8);
  pinMode(enA, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);

  digitalWrite(enA, HIGH);
  
}



void loop (){
  s.write(0);
  delay(500);
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);
  Serial.println("spinning one way");

  delay(2650);
  stop();
  s.write(0);
  s.write(180);
  s.write(0);
  s.write(180);
  delay(3000);
  back();
  delay(4050);
  stop();
  delay(2000);

}

void stop(){
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
  delay(500);
  s.write(180);
}

void back(){
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, HIGH);
}
