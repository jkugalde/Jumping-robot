#include "LegMotor.h"
#include "RobotLeg.h"

int pinsA[4] = {2,4,3,A3};
int pinsB[4] = {8,7,6,A4};

float kA[3] = {1,0.2,0};
float kB[3] = {1,0.2,0};

int refsA[2] = {130,620};
int refsB[2] = {50,500};

RobotLeg RL1;

int newpos=0;
int count=85;
boolean go = false;
unsigned long timer=0;
unsigned long sampler=500;

void setup() {

  Serial.begin(9600);
  RL1.motorpins(pinsA,pinsB);
  RL1.setks(kA,kB);
  RL1.setrefs(refsA,refsB);
  timer=millis();
}

void loop() {

if(millis()-timer>=sampler){
  newpos=newpos+count;
  timer=millis();
  if(newpos>=85 || newpos<=0){
  count=-count;
}
}

RL1.goTo(newpos,newpos);

  
}
