#ifndef LegMotor_h
#define LegMotor_h

#include <Arduino.h>


class LegMotor
{

    public:
    LegMotor();
    ~LegMotor();
    void setk(float k [3]);
    int readPot();
    void assignpins(int pins [4]);
    void act();
    void goTo(int target, int maxvel);
    void setrefs(int refs [2]);
    float setKgrad();
    private:
      int _potval;
      int _pinA;
      int _stateA;
      int _pinB;
      int _stateB;
      int _pinpwm;
      int _pinpot;
      float _Kp;
      float _Kd;
      float _Ki;
      int _preverror;
      int _Ierror;
      int _ref_0;
      int _ref_90;
      float _kgrad;
      int _power;
      float _thI;

};

#endif //LegMotor_H