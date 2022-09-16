#include "RobotLeg.h"
#include "LegMotor.h"

RobotLeg::RobotLeg()
{

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

void RobotLeg::goTo(int x, int y, int pwm){
    _M1.goTo(x,pwm);
    _M2.goTo(y,pwm);
}

int RobotLeg::getPos(int i){
    
    if(i==1){
        return _M1.readSens();
    }
    else{
        return _M2.readSens();
    }
}

void RobotLeg::turnoff(int i){

    if(i==1){
    _M1.turnoff();
    }
    else if(i==2){
     _M2.turnoff();
    }
    else{
    _M1.turnoff();
    _M2.turnoff();
    }


}

void RobotLeg::setrefs(int refA[2],int refB[2]){
    _M1.setrefs(refA);
    _M2.setrefs(refB);
}
