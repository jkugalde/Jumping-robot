#include <LegMotor.h>
#include <Arduino.h>

LegMotor::LegMotor()
{

_Kp=1.0;
_Kd=1.0;
_Ki=1.0;
_ready=true;
_thI=20;
_preverror=0;
_minpos=0;
_maxpos=1023;

}

void LegMotor::assignpins(int pins [3]){
  _pinA=pins[0];
  _pinB=pins[1];
  _pinpot=pins[2];
  pinMode(_pinA,OUTPUT);
  pinMode(_pinB,OUTPUT);
  pinMode(_pinpot,INPUT);
}

LegMotor::~LegMotor()
{
    //dtor
}

void LegMotor::turnoff(){
	_stateA=0;
	_stateB=0;
}

int LegMotor::readPot(){
	_potval=analogRead(_pinpot);
	return _potval;
}

void LegMotor::act(){
	analogWrite(_pinA,_stateA);
	analogWrite(_pinB,_stateB);
}

void LegMotor::setk(float Kp, float Kd, float Ki){
	_Kp=Kp;
  _Kd=Kd;
  _Ki=Ki;
}

void LegMotor::setminmax(int min,int max){
  _minpos=min;
  _maxpos=max;
}

int LegMotor::limits(int target){
  target=constrain(target,_minpos,_maxpos);
  return target;
}

void LegMotor::goTo(int target, int maxvel){

  int pos = readPot();
  target=limits(target);
  int error = target-pos;
  int Derror = error-_preverror;

  int Ierror=Ierror+error; 
  if(abs(error)>_thI){
    Ierror=0;
  }
  
  int pow=int(_Kp*error)-int(_Kd*Derror)+int(_Ki*Ierror);
  _preverror=error;
  
  pow=constrain(pow,-maxvel,maxvel);

  
  if(pow>0){
    _stateA=pow;
    _stateB=0;
  }
  else{  
    _stateA=0;
    _stateB=-pow;
  }

  act();

}
