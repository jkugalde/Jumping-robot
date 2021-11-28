#ifndef LegMotor_h
#define LegMotor_h

#include <Arduino.h>


class LegMotor
{

    public:
    LegMotor();
    ~LegMotor();
    void setk(float Kp, float Kd, float Ki);
    void turnoff();
    int readPot();
    void assignpins(int pins [3]);
    void act();
    void goTo(int target, int maxvel);
    void setminmax(int min, int max);
    int limits(int target);
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

};

#endif //LegMotor_H