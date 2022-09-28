# Hardware

The parts are stored [HERE](https://grabcad.com/library/jumping-robot-leg-1).

The middle joint is designed in this case to hold a 5 mm DI spacer to act as a bushing in the jumping setup, which is a fixed pole.

<img src="/imgs/module.png" width="350">

## Commercial parts

This is the commercial parts list to make a working leg (2 modules), the rest is 3d printing. See the module [repository](https://github.com/jkugalde/N20-Servo-Module) to make 2 modules. 

 ITEM              | QTY
 ---------------------------   | ------------

 M3x18 socket bolt | 1
 M3x12 socket bolt | 2
 M3x6 socket bolt | 4
 M3 Locknut | 3
 Bearing 683ZZ | 3
 Oring 11 DI 2.5 mm t | 2
 Arduino (any Arduino) | 1 
 DRV8801 motor driver | 2

 You also need a power source capable of providing at least 9V at 3A, maybe a 2S LiPo battery. I'm using that motor driver to use the current measurement in the future, but you can use a L298N if you want to do only position control. I did not include the 5 mm aluminium spacer, as you may use another thing in your jumping experimental setup. A dual control driver should be a good idea for the legs, instead of a single driver per motor.

 ## 3D printed parts

 This is the printed parts list:

  ITEM              | QTY
 ---------------------------   | ------------
 Motor joint link | 2
 Link A | 1
 Link B | 1
 Rubber support | 2
 Middle joint | 1

 The parts are printed using a FDM printer. I used PETG as the motor can get hot and weaken the press fit between the motor and the parts. 

 ## Assembly

### Leg

- Once you have 2 modules, joint them together using the middle joint and the M3x6 bolts. The holes in the printed part are smaller than the bolts, so a thread is made.
- Put a bearing inside each hole in the links.
- Join links A and B.
- Put a rubber support in each side.
- Bolt the joint using the M3x18 bolt and locknut. 
- Put the orings in their place.
- Join the links A-B with the motor joint links and the M3x12 bolts.
- Press fit the mechanism in the motor shafts.
