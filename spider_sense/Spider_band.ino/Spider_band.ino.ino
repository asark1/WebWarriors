#include "SR04.h"
#define TRIG_PIN 52
#define ECHO_PIN 50

#define ECHO2 53
#define TRIG2 51
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);

#define MAX_DISTANCE 220

//SR04 sensor2 = SR04(ECHO2, TRIG2);


long distance1;
long oldDistance1;

void setup() {
   Serial.begin(9600);
   delay(1000);


}


//max range for the sensor is 200centimeters
void loop() {


  distance1 = sr04.Distance();
   
  if(distance1 < MAX_DISTANCE)
  {

    Serial.print(distance1);
    Serial.println("cm");
    delay(100);
  }
   

  
  

  // b=sensor2.Distance();
  // Serial.print(b);
  // Serial.println("cm ---------------");
  // delay(1000)


}
