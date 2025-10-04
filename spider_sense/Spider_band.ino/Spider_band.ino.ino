//by Arshdeep Singh, Christian McClain, An Duong, and Luis Rascon


#include "SR04.h"
#include "pwm_speed.h"


// #define TRIG_PIN 52
// #define ECHO_PIN 50

#define ECHO1 31
#define TRIG1 30

#define ECHO2 32
#define TRIG2 33

#define ECHO3 34
#define TRIG3 35

#define ECHO4 36
#define TRIG4 37

#define ECHO5 38
#define TRIG5 39

#define PWM1 2
#define PWM2 4
#define PWM3 6
#define PWM4 8
#define PWM5 10



SR04 sensor1 = SR04(ECHO1,TRIG1);
SR04 sensor2 = SR04(ECHO2,TRIG2);
SR04 sensor3 = SR04(ECHO3,TRIG3);
SR04 sensor4 = SR04(ECHO4,TRIG4);
SR04 sensor5 = SR04(ECHO5,ECHO5);


#define MAX_DISTANCE 300
#define SAMPLES 5
//SR04 sensor2 = SR04(ECHO2, TRIG2);


long distance1[SAMPLES];
long distance2[SAMPLES];
long distance3[SAMPLES];
long distance4[SAMPLES];
long distance5[SAMPLES];

int IND1 = 0;
int IND2 = 0;
int IND3 = 0;
int IND4 = 0;
int IND5 = 0;


long filteredDist1;
long filteredDist2;
long filteredDist3;
long filteredDist4;
long filteredDist5;

void setup() {
  Serial.begin(9600);

  //Sensor 1 filter fill
  for(int i = 0; i < SAMPLES; i++)
  {
    distance1[i] = sensor1.Distance();
  }
  //Sensor 2 filter fill
  for(int i = 0; i < SAMPLES; i++)
  {
    distance2[i] = sensor2.Distance();
  }
  //Sensor 3 filter fill
  for(int i = 0; i < SAMPLES; i++)
  {
    distance3[i] = sensor3.Distance();
  }
  //Sensor 4 filter fill
  for(int i = 0; i < SAMPLES; i++)
  {
    distance4[i] = sensor4.Distance();
  }
  //Sensor 5 filter fill
  for(int i = 0; i < SAMPLES; i++)
  {
    distance5[i] = sensor5.Distance();
  }


}


//FILTERED DISTANCE 1
long filteredDistance1()
{
  distance1[IND1] = sensor1.Distance();
  IND1 = (IND1+1) % SAMPLES;

  long sum = 0;
  for(int l = 0; l < SAMPLES; l++)
  {
      sum += distance1[l];
  }

  long avg = sum / SAMPLES;

  return avg;
}

//FILTERED DISTANCE 2
long filteredDistance2()
{
  distance2[IND2] = sensor2.Distance();
  IND2 = (IND2+1) % SAMPLES;

  long sum = 0;
  for(int l = 0; l < SAMPLES; l++)
  {
      sum += distance2[l];
  }

  long avg = sum / SAMPLES;

  return avg;
}

//FILTERED DISTANCE 3
long filteredDistance3()
{
  distance3[IND3] = sensor3.Distance();
  IND3 = (IND3+1) % SAMPLES;

  long sum = 0;
  for(int l = 0; l < SAMPLES; l++)
  {
      sum += distance3[l];
  }

  long avg = sum / SAMPLES;

  return avg;
}

long filteredDistance4()
{
  distance4[IND4] = sensor4.Distance();
  IND4 = (IND4+1) % SAMPLES;

  long sum = 0;
  for(int l = 0; l < SAMPLES; l++)
  {
      sum += distance4[l];
  }

  long avg = sum / SAMPLES;

  return avg;
}

long filteredDistance5()
{
  distance5[IND5] = sensor5.Distance();
  IND5 = (IND5+1) % SAMPLES;

  long sum = 0;
  for(int l = 0; l < SAMPLES; l++)
  {
      sum += distance5[l];
  }

  long avg = sum / SAMPLES;

  return avg;
}


//max range for the sensor is 200centimeters
void loop() {


  //SENSOR 1 AND MOTOR 1 BLOCK
  filteredDist1 = filteredDistance1();
  if(filteredDist1 < MAX_DISTANCE)
  {
    Serial.print("\n filtered: ");
    Serial.print(filteredDist1);
    Serial.println("cm");
  
    if(filteredDist1 < 30)
    {
      level3_speed(PWM1);
    }
    else if(filteredDist1 < 100)
    {
      level2_speed(PWM1);
    }
    else if(filteredDist1 < 150)
    {
      level1_speed(PWM1);
    }
    else
    {
      level0_speed(PWM1);
    }
  }


  //SENSOR 2 AND MOTOR 2 BLOCK
  filteredDist2 = filteredDistance2();
  if(filteredDist2 < MAX_DISTANCE)
  {
    Serial.print("\n filtered: ");
    Serial.print(filteredDist2);
    Serial.println("cm");
  
    if(filteredDist2 < 30)
    {
      level3_speed(PWM2);
    }
    else if(filteredDist2 < 100)
    {
      level2_speed(PWM2);
    }
    else if(filteredDist2 < 150)
    {
      level1_speed(PWM2);
    }
    else
    {
      level0_speed(PWM2);
    }
  }

  //SENSOR 3 AND MOTOR 3 BLOCK
  filteredDist3 = filteredDistance3();
  if(filteredDist3 < MAX_DISTANCE)
  {
    Serial.print("\n filtered: ");
    Serial.print(filteredDist3);
    Serial.println("cm");
  
    if(filteredDist3 < 30)
    {
      level3_speed(PWM3);
    }
    else if(filteredDist3 < 100)
    {
      level2_speed(PWM3);
    }
    else if(filteredDist3 < 150)
    {
      level1_speed(PWM3);
    }
    else
    {
      level0_speed(PWM3);
    }
  }


    //SENSOR 4 AND MOTOR 4 BLOCK
  filteredDist4 = filteredDistance4();
  if(filteredDist4 < MAX_DISTANCE)
  {
    Serial.print("\n filtered: ");
    Serial.print(filteredDist4);
    Serial.println("cm");
  
    if(filteredDist4 < 30)
    {
      level3_speed(PWM4);
    }
    else if(filteredDist4 < 100)
    {
      level2_speed(PWM4);
    }
    else if(filteredDist4 < 150)
    {
      level1_speed(PWM4);
    }
    else
    {
      level0_speed(PWM4);
    }
  }

    //SENSOR 5 AND MOTOR 5 BLOCK
  filteredDist5 = filteredDistance5();
  if(filteredDist5 < MAX_DISTANCE)
  {
    Serial.print("\n filtered: ");
    Serial.print(filteredDist5);
    Serial.println("cm");
  
    if(filteredDist5 < 30)
    {
      level3_speed(PWM5);
    }
    else if(filteredDist5 < 100)
    {
      level2_speed(PWM5);
    }
    else if(filteredDist5 < 150)
    {
      level1_speed(PWM5);
    }
    else
    {
      level0_speed(PWM5);
    }
  }
   

  
  delay(100);


}
