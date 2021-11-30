#include <LegMotor.h>
#include <Arduino.h>

LegMotor::LegMotor()
{

_Kp=0.5;
_Kd=0.5;
_Ki=0;
_ready=true;
_thI=20;
_preverror=0;
_minpos=0;
_maxpos=1023;
_ref_0=0;

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

void LegMotor::setk(float k [3]){
	_Kp=k[0];
  _Kd=k[1];
  _Ki=k[2];
}

void LegMotor::setminmax(int min,int max){
  _minpos=min;
  _maxpos=max;
}

int LegMotor::limits(int target){
  target=constrain(target,_minpos,_maxpos);
  return target;
}

int LegMotor::setref0(){
  float meanval=0;
  for(int i = 0;i<5000;i++){
    meanval=meanval+readPot();
  }
  _ref_0=int(meanval/5000);
  return _ref_0;
}

int LegMotor::setref90(){
  float meanval=0;
  for(int i = 0;i<5000;i++){
    meanval=meanval+readPot();
  }
  _ref_90=int(meanval/5000);
  return _ref_90;
}

float LegMotor::setKgrad(){
  _kgrad=float((_ref_90-_ref_0)/90.0);
  return _kgrad;
}

void LegMotor::setrefs(int refs[2]){
  _ref_0=refs[0];
  _ref_90=refs[1];
  setKgrad();
}

void LegMotor::goTo(int target, int maxvel){


  target=int(_kgrad*target)+_ref_0;
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
