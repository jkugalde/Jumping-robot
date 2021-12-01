#include "LegMotor.h"

int pins[4] = {8,7,6,A4};
float k [3] = {1,0.2,0};
int refsA[2] = {130,620};

int newpos=45;
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

if(Serial.available()>0){
  newpos=Serial.parseInt();
  Serial.flush();
 Serial.println(newpos);
}

//if(millis()-timer>=sampler){
//  newpos=newpos+count;
//  timer=millis();
//  if(newpos>50 || newpos<=0){
//  count=-count;
//}
//}


 LM1.goTo(newpos,255);

  
}
