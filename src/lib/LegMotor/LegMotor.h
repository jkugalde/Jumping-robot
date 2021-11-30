#ifndef LegMotor_h
#define LegMotor_h

#include <Arduino.h>


class LegMotor
{

    public:
    LegMotor();
    ~LegMotor();
    void setk(float k [3]);
    void turnoff();
    int readPot();
    void assignpins(int pins [3]);
    void act();
    void goTo(int target, int maxvel);
    void setminmax(int min, int max);
    int limits(int target);
    int setref0();
    int setref90();
    void setrefs(int refs [2]);
    float setKgrad();
    private:
      int _potval;
      int _pinA;
      int _stateA;
      int _pinB;
      int _stateB;
      int _pinpot;
      float _Kp;
      float _Kd;
      float _Ki;
      bool _ready;
      int _thI;
      int _preverror;
      int _Ierror;
      int _minpos;
      int _maxpos;
      int _ref_0;
      int _ref_90;
      float _kgrad;

};

#endif //LegMotor_H