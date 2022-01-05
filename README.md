# N20-Leg-Actuator

An inexpensive leg actuator for jumping and walking tetrapods based on a N20 servo module.

## Summary

<img src="/imgs/isocad.png" width="500">

The N20 is a DC brushed motor made by Pololu, it comes with different gears ratio and power output, but at the same size, so the idea is that you can use the same module for different projects, depending on the torque or rpm desired.

This module converts the N20 into a servo to control the axis angular position, using a small, lightweight and with very low friction angle sensor. In this project i use 2 modules to make a jumping leg.

<img src="/imgs/module.png" width="500">

A 2x3 pin header male connector is located on top of the module, connected to the motor and sensor pins. There is also a coupling piece between the motor shaft and the angle sensor, as the shaft is 3 mm and the angle sensor is for 4 mm shafts.

The middle joint is designed in this case to hold a 5 mm DI spacer to act as a bushing in the jumping setup.

Currently, i have made some Arduino libraries to play with the leg actuator, and it can jump as you can see in this [video](https://youtu.be/bBeYL-RNnhY). 

This is the commercial parts list to make a working leg, the rest is 3d printing. 

 ITEM              | QTY
 ---------------------------   | ------------
 Pololu N20 Brushed DC Motor 6V HP 1:10 GR| 2
 Angle sensor CJMCU-103 | 2
 M3x18 socket bolt | 1
 M3x12 socket bolt | 2
 M3x6 socket bolt | 4
 M3 Locknut | 3
 Bearing 683ZZ | 3
 Oring 11 DI 2.5 mm t | 2
 2x3 male pin headers (2.54mm) | 2
 Arduino (any Arduino) | 1 
 DRV8801 motor driver | 2

 You also need a power source capable of providing at least 7V at 3A, like a 2S LiPo battery. I'm using that motor driver to later use the current measurement, but you can use a L298N if you want to do only position control. I did not include the 5 mm aluminium spacer, as you may use another thing in your jumping experimental setup.

 This is the printed parts list

  ITEM              | QTY
 ---------------------------   | ------------
 Motor case | 2
 Motor joint link | 2
 Adapter   | 2
 Link A | 1
 Link B | 1
 Rubber support | 2
 Middle joint | 1

## First experiments

With the 3000 RPM (1:10 gearbox) motor, the robot barely jumps at a voltage (9V) higher than the nominal (6V), which can be damaging it. A motor with at least twice the torque should be enough to have a better performance without losing too much speed, but further calculations are needed.


## Further Work

- To use a Teensy instead of an Arduino.
- Characterize the DC motor to generate a dynamic control using torque and current.
- Make a PCB to control 8 motors.
- Make a tetrapod.
- To write assembly instructions