#ifndef RobotLeg_h
#define RobotLeg_h

#include "LegMotor.h"

class RobotLeg
{

    public:
    RobotLeg();
    ~RobotLeg();
    void motorpins(int pinsA [4], int pinsB [4]);
    void goTo(int x, int y, int pwm);
    void setrefs(int refA[2], int refB[2]);
    void setks(float kA [3], float kB [3]);
    void turnoff(int i);
    int getPos(int i);
    private:
      LegMotor _M1;
      LegMotor _M2;

};

#endif //RobotLeg
