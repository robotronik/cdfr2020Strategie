#include <Arduino.h>


struct Location
{
  float x, y;


  Location(float InX, float InY)
    :x(InX), y(InY)
  {}

  Location operator+(Location Other)
  {
    return Location(x+Other.x, y+Other.y);
  }
};

int state=0;
float RobotAngle;
Location RobotLocation;

void RobotLookAt(float angle) //blocking
{
  //do stuff
}

void RobotLookAtLocation(Location Target) //blocking
{
  //atan2 to get the angle then RobotLookAt
}

void RobotGoTo(Location target) //blocking
{
  //Look at location then go to it
}

void RobotDeployArm();

void RobotRetractArm();

float GetGirouetteValue();

void SetScore(int value);

void machine()
{
  
}


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}