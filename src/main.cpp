#include <Arduino.h>

// intialize forward drive pins
int ENA_fwd = 7;
int IN1_fwd = 6;
int IN2_fwd = 5;
int IN3_fwd = 4;
int IN4_fwd = 3;
int ENB_fwd = 2;

// intialize rear drive pins
int ENA_rwd = 13;
int IN1_rwd = 12;
int IN2_rwd = 11;
int IN3_rwd = 10;
int IN4_rwd = 9;
int ENB_rwd = 8;

void setup() {
  pinMode(ENA_fwd, OUTPUT);
  pinMode(ENB_fwd, OUTPUT);
  pinMode(IN1_fwd, OUTPUT);
  pinMode(IN2_fwd, OUTPUT);
  pinMode(IN3_fwd, OUTPUT);
  pinMode(IN4_fwd, OUTPUT);

  pinMode(ENA_rwd, OUTPUT);
  pinMode(ENB_rwd, OUTPUT);
  pinMode(IN1_rwd, OUTPUT);
  pinMode(IN2_rwd, OUTPUT);
  pinMode(IN3_rwd, OUTPUT);
  pinMode(IN4_rwd, OUTPUT);
  
  digitalWrite(IN1_fwd, LOW);
  digitalWrite(IN2_fwd, LOW);
  digitalWrite(IN3_fwd, LOW);
  digitalWrite(IN4_fwd, LOW);

  digitalWrite(IN1_rwd, LOW);
  digitalWrite(IN2_rwd, LOW);
  digitalWrite(IN3_rwd, LOW);
  digitalWrite(IN4_rwd, LOW);
}
void loop() {

   analogWrite(ENA_fwd, 255);
  analogWrite(ENB_fwd, 255);
  digitalWrite(IN1_fwd, HIGH);
  digitalWrite(IN2_fwd, LOW);
  digitalWrite(IN3_fwd, HIGH);
  digitalWrite(IN4_fwd, LOW);

  /*setDirection();
  delay(1000);
  changeSpeed();
  delay(1000);
}
void setDirection() {
  analogWrite(ENA_fwd, 255);
  analogWrite(ENB_fwd, 255);
  digitalWrite(IN1_fwd, HIGH);
  digitalWrite(IN2_fwd, LOW);
  digitalWrite(IN3_fwd, HIGH);
  digitalWrite(IN4_fwd, LOW);

  analogWrite(ENA_rwd, 255);
  analogWrite(ENB_rwd, 255);
  digitalWrite(IN1_rwd, HIGH);
  digitalWrite(IN2_rwd, LOW);
  digitalWrite(IN3_rwd, HIGH);
  digitalWrite(IN4_rwd, LOW);
  delay(5000);
  
  digitalWrite(IN1_fwd, LOW);
  digitalWrite(IN2_fwd, HIGH);
  digitalWrite(IN3_fwd, LOW);
  digitalWrite(IN4_fwd, HIGH);

  digitalWrite(IN1_rwd, LOW);
  digitalWrite(IN2_rwd, HIGH);
  digitalWrite(IN3_rwd, LOW);
  digitalWrite(IN4_rwd, HIGH);
  delay(5000);
  
  digitalWrite(IN1_fwd, LOW);
  digitalWrite(IN2_fwd, LOW);
  digitalWrite(IN3_fwd, LOW);
  digitalWrite(IN4_fwd, LOW);

  digitalWrite(IN1_rwd, LOW);
  digitalWrite(IN2_rwd, LOW);
  digitalWrite(IN3_rwd, LOW);
  digitalWrite(IN4_rwd, LOW);
}
void changeSpeed() {
  digitalWrite(IN1_fwd, LOW);
  digitalWrite(IN2_fwd, HIGH);
  digitalWrite(IN3_fwd, LOW);
  digitalWrite(IN4_fwd, HIGH);

  digitalWrite(IN1_rwd, LOW);
  digitalWrite(IN2_rwd, HIGH);
  digitalWrite(IN3_rwd, LOW);
  digitalWrite(IN4_rwd, HIGH);
  
  for (int i = 0; i < 256; i++) {
    analogWrite(ENA_fwd, i);
    analogWrite(ENA_rwd, i);
    analogWrite(ENB_fwd, i);
    analogWrite(ENB_rwd, i);
    delay(20);
  }
  
  for (int i = 255; i >= 0; --i) {
    analogWrite(ENA_fwd, i);
    analogWrite(ENA_rwd, i);
    analogWrite(ENB_fwd, i);
    analogWrite(ENB_rwd, i);
    delay(20);
  }
  
  digitalWrite(IN1_fwd, LOW);
  digitalWrite(IN2_fwd, LOW);
  digitalWrite(IN3_fwd, LOW);
  digitalWrite(IN4_fwd, LOW);

  digitalWrite(IN1_rwd, LOW);
  digitalWrite(IN2_rwd, LOW);
  digitalWrite(IN3_rwd, LOW);
  digitalWrite(IN4_rwd, LOW);*/
}
