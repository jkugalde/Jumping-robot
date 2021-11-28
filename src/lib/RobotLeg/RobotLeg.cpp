#include <RobotLeg.h>
#include <Arduino.h>
#include <LegMotor.h>

RobotLeg::RobotLeg()
{

}

RobotLeg::~RobotLeg()
{
    //dtor
}

void RobotLeg::motorpins(int pinsA [3], int pinsB [3]){
    _M1.assignpins(pinsA);
    _M2.assignpins(pinsB);
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