#include "RobotLeg.h"

const int pinsA[4] = {2,3,A0,4}; // dir, pwm, sensor in, sleep. 
const int pinsB[4] = {8,9,A1,10};

const float kA[3] = {2,0.2,0}; // PID values, kp, kd, ki
const float kB[3] = {2,0.2,0};

const int refsA[2] = {530,260}; //analog reference for angle 0 and 90 (from the vertical)
const int refsB[2] = {513,240};

RobotLeg RL1; //creates the leg

int newpos1=45; //initial angles
int newpos2=45;

const int leg_pwm=180; //max power in actuator

int count=0; //index
const int nmoves = 14; //quantity of preprogrammed moves

const int q1[nmoves]={35,50,60,70,72,74,72,70,60,50,35,32,30,32}; // pre programmed moves
const int q2[nmoves]={74,72,70,60,50,35,32,30,32,50,60,70,72,74};

unsigned long timer=0;
unsigned long dt = 25; //time between each movement

void setup() {

  Serial.begin(9600);
  RL1.motorpins(pinsA,pinsB); //assign pns
  RL1.setks(kA,kB); //assign pid constants
  RL1.setrefs(refsA,refsB); //assign references
  timer=millis(); //set timer

RL1.goTo(newpos1,newpos2,leg_pwm); //initial position

delay(2000); //wait
  
}

void loop() {

if(millis()-timer>=dt){  //this sweeps the arrays

  newpos1=q1[count];
  newpos2=q2[count];
  count=count+1;
  if(count==nmoves-1){
  count=0;
  }
  timer=millis();
}

RL1.goTo(newpos1,newpos2,leg_pwm);
  
}
