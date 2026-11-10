const int PWMA = 12;
const int AIN1 = 11;
const int AIN2 = 10;
const int STBY = 9;
const int BIN1 = 8;
const int BIN2 = 7;
const int PWMB = 6;
const int UltraSend = 5;
const int UltraRec = 4;
const int ServoPin = 3;
int pwm = 150;
int left,right,cm,duration;

#include <Servo.h>
Servo servo1;
int pos = 90;

void TurnRight() {
  pos = 90;
  digitalWrite(AIN1, HIGH);//left forward
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);//right backward
  digitalWrite(BIN2, HIGH);
  delay(15);//certain time until it fully turns 90 degrees depending on your car situation
  digitalWrite(BIN1, HIGH);//right forward
  digitalWrite(BIN2, LOW);
  
}

void TurnLeft() {
  pos = 90;
  digitalWrite(AIN1, LOW);//left backward
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH);//right forward
  digitalWrite(BIN2, LOW);
  delay(15);
  digitalWrite(AIN1, HIGH);//left forward
  digitalWrite(AIN2, LOW);
  
}

void MoveBack() {
  digitalWrite(AIN1, LOW);//left backward
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);//right backward
  digitalWrite(BIN2, HIGH);

}
//car tops
void Stop() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
//
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  //motor driver
  //
  pinMode(UltraSend,OUTPUT);
  pinMode(UltraRec, INPUT);
  // Ultrasound
  //
  pinMode(ServoPin,OUTPUT);
  servo1.attach(ServoPin);
  //Servo
  digitalWrite(STBY, HIGH);

}

void loop() {

  digitalWrite(UltraSend,LOW);
  delayMicroseconds(2);// short low pulse and give a clear high pulse for a clear answer _ _ - - - - - _ _
  digitalWrite(UltraSend,HIGH);
  delayMicroseconds(5);
  digitalWrite(UltraSend,LOW);

  duration = pulseIn(UltraRec,HIGH); // read the duration of the high pulse
  cm = microsecondsToCentimeters(duration);

  //moving forward
  digitalWrite(AIN1, HIGH);//left forward
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, pwm);
  digitalWrite(BIN1, HIGH);//right forward
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, pwm);

  if (cm <= 5) {
    Stop();
    pos = 0;
    servo1.write(pos);
    delay(500);
    left = cm;
    pos = 180;
    servo1.write(pos);
    delay(500);
    right = cm;
    if (right > left){
      TurnRight();
    }
    else if (left > right){
      TurnLeft();
    }
    else if (left == right){
      MoveBack();
    }
  }
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds /29/2;
}
