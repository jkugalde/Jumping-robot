#include "LegMotor.h"
#include "RobotLeg.h"

int pinsA[3] = {3,5,A3};
int pinsB[3] = {6,9,A4};

int newpos = 0;

RobotLeg RL1;


void setup() {
  
  RL1.motorpins(pinsA,pinsB);
  Serial.begin(9600);

}

void loop() {

 if(Serial.available()>0){
  
 newpos = Serial.parseInt();
 Serial.println(newpos);
 
 }

Serial.print(RL1.getPos(1));
Serial.print("    ");
Serial.println(RL1.getPos(2));

  
}
