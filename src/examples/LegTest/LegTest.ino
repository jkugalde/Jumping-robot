#include "LegMotor.h"
#include "RobotLeg.h"

//this program is a sweep

int pinsA[3] = {2,3,A0};
int pinsB[3] = {8,9,A1};

float kA[3] = {2,0.2,0};
float kB[3] = {2,0.2,0};

int refsA[2] = {510,790};
int refsB[2] = {510,790};

int pos[2] = {0,85};

RobotLeg RL1;

int newpos=0;
boolean count=0;
unsigned long timer=0;
unsigned long times[2]={300,150};

void setup() {

  RL1.motorpins(pinsA,pinsB);
  RL1.setks(kA,kB);
  RL1.setrefs(refsA,refsB);
  timer=millis();
}

void loop() {

if(millis()-timer>=times[count]){
  newpos=pos[count];
  timer=millis();
  count=!count;
}

RL1.goTo(newpos,newpos);
  
}
