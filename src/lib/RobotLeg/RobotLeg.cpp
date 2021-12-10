#include <RobotLeg.h>
#include <Arduino.h>
#include <LegMotor.h>

RobotLeg::RobotLeg()
{
_maxangle=85;
}

RobotLeg::~RobotLeg()
{
    //dtor
}

void RobotLeg::motorpins(int pinsA [4], int pinsB [4]){
    _M1.assignpins(pinsA);
    _M2.assignpins(pinsB);
}

void RobotLeg::setks(float kA [3], float kB [3]){
    _M1.setk(kA);
    _M2.setk(kB);

}

void RobotLeg::goTo(int x, int y){
    _M1.goTo(x,255);
    _M2.goTo(y,255);
}

int RobotLeg::getPos(int i){
    
    if(i==1){
        return _M1.readPot();
    }
    else{
        return _M2.readPot();
    }
}


void RobotLeg::setrefs(int refA[2],int refB[2]){
    _M1.setrefs(refA);
    _M2.setrefs(refB);
}