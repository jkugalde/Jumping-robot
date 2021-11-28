#include "LegMotor.h"

int pins[3] = {3,5,A3};
int newpos = 0;

LegMotor LM1;


void setup() {
  
  LM1.assignpins(pins);
  LM1.setk(1,1,0);
  LM1.setminmax(150,950);
  newpos=LM1.readPot();
  Serial.begin(9600);

}

void loop() {

 if(Serial.available()>0){
  
 newpos = Serial.parseInt();
 Serial.println(newpos);
 
 }


LM1.goTo(newpos,255);

  
}
