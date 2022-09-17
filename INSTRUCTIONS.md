# Hardware

The parts are stored [HERE](https://grabcad.com/library/jumping-robot-leg-1).

A 2x3 pin header male connector is located on top of the module, connected to the motor and sensor pins. There is also an adapter piece between the motor shaft and the angle sensor, as the shaft is 3 mm and the angle sensor is for 4 mm shafts.

The middle joint is designed in this case to hold a 5 mm DI spacer to act as a bushing in the jumping setup, which is a fixed pole.

<img src="/imgs/module.png" width="350">

## Commercial parts

This is the commercial parts list to make a working leg (2 modules), the rest is 3d printing. 

 ITEM              | QTY
 ---------------------------   | ------------
 Pololu N20 Brushed DC Motor| 2
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

 You also need a power source capable of providing at least 7V at 3A, like a 2S LiPo battery. I'm using that motor driver to use the current measurement in the future, but you can use a L298N if you want to do only position control. I did not include the 5 mm aluminium spacer, as you may use another thing in your jumping experimental setup. A dual control driver should be a good idea for the legs, instead of a single driver per motor.

 ## 3D printed parts

 This is the printed parts list:

  ITEM              | QTY
 ---------------------------   | ------------
 Motor case | 2
 Motor joint link | 2
 Adapter   | 2
 Link A | 1
 Link B | 1
 Rubber support | 2
 Middle joint | 1

 The parts are printed using a FDM printer. I used PETG as the motor can get hot and weaken the press fit between the motor and the parts. The adapter was printed using a 0.3 mm nozzle, as is a very small piece.

 ## Assembly

### Module

First, a 2x3 pin header must be soldered in the angle sensor. Then:

- Insert the angle sensor in the motor case.
- Insert the motor in the case, and the shaft through the angle sensor. You may need to rotate the shaft to match with the angle sensor.
- Insert the adapter.
- Solder two wires in the motor terminals and in the male pins as the Figure indicates.

<img src="/imgs/solder.png" width="350">

### Leg

- Once you have 2 modules, joint them together using the middle joint and the M3x6 bolts. The holes in the printed part are smaller than the bolts, so a thread is made.
- Put a bearing inside each hole in the links.
- Join links A and B.
- Put a rubber support in each side.
- Bolt the joint using the M3x18 bolt and locknut. 
- Put the orings in their place.
- Join the links A-B with the motor joint links and the M3x12 bolts.
- Press fit the mechanism in the motor shafts.
