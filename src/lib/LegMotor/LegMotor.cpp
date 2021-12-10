#include <LegMotor.h>
#include <Arduino.h>

LegMotor::LegMotor()
{

_Kp=0.5;
_Kd=0.5;
_Ki=0;
_preverror=0;
_ref_0=0;
_power=0;
_thI=0;

}

void LegMotor::assignpins(int pins [4]){
  _pinA=pins[0];
  _pinB=pins[1];
  _pinpwm=pins[2];
  _pinpot=pins[3];
  pinMode(_pinA,OUTPUT);
  pinMode(_pinB,OUTPUT);
  pinMode(_pinpwm,OUTPUT);
  pinMode(_pinpot,INPUT);
}

LegMotor::~LegMotor()
{
    //dtor
}

int LegMotor::readPot(){
	_potval=analogRead(_pinpot);
	return _potval;
}

void LegMotor::act(){
	digitalWrite(_pinA,_stateA);
	digitalWrite(_pinB,_stateB);
  analogWrite(_pinpwm,_power);
}

void LegMotor::setk(float k [3]){
	_Kp=k[0];
  _Kd=k[1];
  _Ki=k[2];
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
    _stateA=1;
    _stateB=0;
    _power=pow;
  }
  else{  
    _stateA=0;
    _stateB=1;
    _power=-pow;
  }

  act();

}
