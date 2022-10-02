# Jumping Robot

I used 2 [N20 Servo Modules](https://github.com/jkugalde/N20-Servo-Module) to make a jumping five bar parallel robot. 

## Summary

I printed a mechanical linkage to make a 5 bar mechanism using the modules. The assembly instructions are [HERE](INSTRUCTIONS.md).

<img src="/imgs/isocad.png" width="350">

## First experiments

With the 3000 RPM (1:10 gearbox) motor, the robot barely jumps at a voltage (9V) higher than the nominal (6V), which can be damaging it. A motor with at least twice the torque should be enough to have a better performance without losing too much speed, but further calculations are needed.

Currently, i have made some Arduino libraries to play with the leg, and it can jump as you can see in this [video](https://youtu.be/bBeYL-RNnhY). 

## Further Work

- To use a Teensy instead of an Arduino.
- Write direct and inverse kynematics.
- Make a PCB.
- Add some compliancy.