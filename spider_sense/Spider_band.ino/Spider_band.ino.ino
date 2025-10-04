#include "SR04.h"
#define TRIG_PIN 52
#define ECHO_PIN 50

#define ECHO2 53
#define TRIG2 51
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);

#define MAX_CHANGE 300

SR04 sensor2 = SR04(ECHO2, TRIG2);


long newDistance;
long oldDistance;

void setup() {
   Serial.begin(9600);
   delay(1000);
  oldDistance = sr04.Distance();
}


//max range for the sensor is 200centimeters
void loop() {


  newDistance=sr04.Distance();
   
  if(abs(newDistance - oldDistance) < MAX_CHANGE)
  {
    Serial.print(newDistance);
    Serial.println("cm");
    delay(100);
  }
   

  // b=sensor2.Distance();
  // Serial.print(b);
  // Serial.println("cm ---------------");
  // delay(1000)
  
  
  


}
