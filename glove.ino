#include "UltrasonicSensor.h"

#define num_of_engines 3
#define Minimum_voltag_per_engine 70

UltrasonicSensor Dsensor(7,8);//trig, echo
short engines[] = {5,10,11}; //must be PWM pin
float Distance;
short TurnedOnEngine;

void setup() 
{
  TurnOff();
}

void loop() 
{
  Distance = Dsensor.GetAvg();
  if(!(TurnedOnEngine = map(Distance, 4, 150, 0, num_of_engines)))
  {
    TurnOff();
    TurnedOnEngine = map(Distance, 4, 150, 0, num_of_engines);
  }
  analogWrite(TurnedOnEngine, map(Distance, 4, 150, 0, Minimum_voltag_per_engine));
}

void TurnOff()
{
  for(short i = 0; i < num_of_engines; ++i)
  {
    digitalWrite(engines[i], LOW);
  }
}
