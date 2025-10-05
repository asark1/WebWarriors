#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position
const int servoPin = 13;
const int launchPin = 12;
const int retractPin = 7;
int launchState = 0;
int retractState = 0;
int pwm = 128;

void setup() 
{
  //Serial.begin(115200);
  myservo.attach(servoPin);  // attaches the servo on pin 13 to the servo object
  // initialize the pushbutton pin as an input:
  pinMode(launchPin, INPUT);
  pinMode(retractPin, OUTPUT);
}

void loop() 
{
  // read the state of the pushbutton value:
  launchState = digitalRead(launchPin);
  retractState = digitalRead(retractPin);
  analogWrite(retractPin, pwm);
 // Serial.print("PWM = ");
 // Serial.print(pwm);
 // pwm += 10;
  //delay(100);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (launchState == HIGH) 
  {
    for (pos = 0; pos <= 100; pos += 1) // goes from 0 degrees to 90 degrees
    { 
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  } 
  pos = 0;
  
}