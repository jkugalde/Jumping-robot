#ifndef RobotLeg_h
#define RobotLeg_h

#include <Arduino.h>
#include <LegMotor.h>


class RobotLeg
{

    public:
    RobotLeg();
    ~RobotLeg();
    void motorpins(int pinsA [3], int pinsB [3]);
    void goTo(int x, int y);
    void calibrateminmax();
    void setrefs(int refA[2], int refB[2]);
    void setks(float kA [3], float kB [3]);
    int getPos(int i);
    private:
      LegMotor _M1;
      LegMotor _M2;

};

#endif //RobotLeg