#include "LegMotor.h"

int pins[3] = {5,3,A3};
float k [3] = {1.5,0.2,0};
int refsA[2] = {130,620};

int newpos=0;
int count=50;
boolean go = false;
unsigned long timer=0;
unsigned long sampler=200;

LegMotor LM1;


void setup() {
  
  LM1.assignpins(pins);
  LM1.setk(k);
  Serial.begin(9600);
  LM1.setrefs(refsA);
  LM1.setKgrad();
  timer=millis();

}

void loop() {

if(millis()-timer>=sampler){
  newpos=newpos+count;
  timer=millis();
  if(newpos>50 || newpos<=0){
  count=-count;
}
}


 LM1.goTo(newpos,255);

  
}
