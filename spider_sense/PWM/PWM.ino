#include "pwm_speed.h"

int motor2 = 2;      // motor connected to digital pin 2
int motor4 = 4;      // motor connected to digital pin 4
int motor6 = 6;      // motor connected to digital pin 6
int motor8 = 8;      // motor connected to digital pin 8
int motor10 = 10;      // motor connected to digital pin 8
int analogPin = A0;  // potentiometer connected to analog pin A0
int val = 122;         // variable to store the read value
int i = 0;

void setup() {
  pinMode(motor2, OUTPUT);  // sets the pin as output
  pinMode(motor4, OUTPUT);  // sets the pin as output
  pinMode(motor6, OUTPUT);  // sets the pin as output
  pinMode(motor8, OUTPUT);  // sets the pin as output
  pinMode(motor10, OUTPUT);  // sets the pin as output
}

void loop() {
  val = analogRead(analogPin);  // read the input pin
  level0_speed(motor2);
  level1_speed(motor4);
  level2_speed(motor6);
  level3_speed(motor8);

  while(1)
  {
    analogWrite(motor10, i);
    delay(100);
    i += 2;
    if (i >= 255)
    {
      i = 0;
    }
  }
}