#include "LegMotor.h"
#include "RobotLeg.h"

int pinsA[3] = {5,3,A3};
int pinsB[3] = {9,6,A4};

RobotLeg RL1;

void setup() {
  
  RL1.motorpins(pinsA,pinsB);
  Serial.begin(9600);
  
  RL1.setrefs();

}

void loop() {


  
}
