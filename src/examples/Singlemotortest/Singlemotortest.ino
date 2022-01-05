#include "LegMotor.h"

int pins[3] = {8,9,A1};
float k [3] = {0.7,0.4,0};
int refsA[2] = {540,800};

int newpos; //degrees
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
  newpos=0;

}

void loop() {

if(Serial.available()>0){
  newpos=Serial.parseInt();
  Serial.flush();
 Serial.println(newpos);
}

LM1.goTo(newpos,255);
  
}
