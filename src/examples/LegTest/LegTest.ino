#include "RobotLeg.h"

const int pinsA[4] = {2,3,A0,4}; // dir, pwm, sensor in, sleep. 
const int pinsB[4] = {8,9,A1,10};

const float kA[3] = {4,0.2,0}; // PID values, kp, kd, ki
const float kB[3] = {4,0.2,0};

const int refsA[2] = {785,530}; //analog reference for angle 0 and 90 (from the horizontal)
const int refsB[2] = {770,500};

const float leglengths[5]={25.0,50.0,25.0,50.0,56.3};
RobotLeg RL1(leglengths); //creates the leg

int newpos1=45; //initial angles
int newpos2=45;

const int leg_pwm=255; //max power in actuator

int count=0; //index
int cual = 0;
const int nmoves = 2; //quantity of preprogrammed moves

const int q1[nmoves]={140,90}; // pre programmed moves
//const int q2[nmoves]={74,72,70,60,50,35,32,30,32,50,60,70,72,74};

unsigned long timer = 0;
unsigned long dt = 400; //time between each movement

void setup() {

  Serial.begin(9600);
  RL1.motorpins(pinsA,pinsB); //assign pns
  RL1.setks(kA,kB); //assign pid constants
  RL1.setrefs(refsA,refsB); //assign references
  RL1.dirs(false,true);
  timer=millis(); //set timer

RL1.goTo(newpos1,newpos2,leg_pwm); //initial position

delay(2000); //wait
  
}

void loop() {

if(millis()-timer>=dt){  //this sweeps the arrays

  newpos1=q1[count];
  newpos2=180-newpos1;
  count=count+1;
  if(count==nmoves){
  count=0;
  }
  timer=millis();
}

// if(Serial.available()>0){
// if(cual==0){

// newpos1=Serial.parseInt();
// cual=cual+1;
// }
// else{
// newpos2=Serial.parseInt();
// RL1.ik(newpos1,newpos2,255);
// cual=0;  
// }
// }

RL1.goTo(newpos1,newpos2,leg_pwm);
  
}
