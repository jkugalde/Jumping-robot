# N20-Leg-Actuator

I made a custom servo motor using a cheap N20 DC motor and an angle sensor. Then, i used this module to make a jumping five bar parallel robot. The goal is to make a tetrapod.

## Summary

<img src="/imgs/module.png" width="350">

The N20 is a DC brushed motor format. It comes in different gears ratio and power outputs, but at the same size, so the idea is that you can use the same module for different projects, depending on the torque or rpm desired.

This module converts the N20 into a servo, to control the shaft angular position, using a small, lightweight and with very low friction angle sensor (CJMCU-103). In this project i use 2 modules to make a jumping leg, [HERE](INSTRUCTIONS.md) are the instructions.

<img src="/imgs/isocad.png" width="350">

## First experiments

With the 3000 RPM (1:10 gearbox) motor, the robot barely jumps at a voltage (9V) higher than the nominal (6V), which can be damaging it. A motor with at least twice the torque should be enough to have a better performance without losing too much speed, but further calculations are needed.

Currently, i have made some Arduino libraries to play with the leg actuator, and it can jump as you can see in this [video](https://youtu.be/bBeYL-RNnhY). 

## Further Work

- To use a Teensy instead of an Arduino.
- Characterize the DC motor to generate a dynamic control using torque and current.
- Write direct and inverse kynematics.
- Make a PCB to control 8 motors.
- Make a tetrapod.