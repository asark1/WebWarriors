#include <Arduino.h>
#include "pwm_speed.h"

void level0_speed(int pin)
{
    analogWrite(pin, 0);
}

void level1_speed(int pin)
{
    analogWrite(pin, 50);
}

void level2_speed(int pin)
{
    analogWrite(pin, 153);
}

void level3_speed(int pin)
{
    analogWrite(pin, 255);
}