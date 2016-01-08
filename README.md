# OneShot125mbed

## Description

I just wrote this little library to use an ESC running BlHeli with OneShot125 with mbed stuff.
It use the `PwmOut` of the mbed library so you have to compile with the mbed sdk.

## Dependencies

You have to compile with the mbed SDK.
In the file `oneshot.h` I perform a `#include "mbed.h"`


## How to use

Just instance the class `OneShot125` with a pin in parameter and use the method `setPercent(flaot)` with in arg the percent of speed.

```
OneShot125 my_motor(PA_7, false); /*Instantiate a new OneSHot motor on pin PA_7 (0x07)*/
my_motor.stdSetPercent(50); /*Set the rotation speed at 50% of the max speed*/

```

## Unidirectional / bidirectional motor

In bidirectional mode, center throttle is zero and above is fwd rotation and below is reverse rotation unlike in unidirectional mode, throttle is 0% at 0 throttle stick and 100% at full throttle stick.

### Unidirectional motor

```
OneShot125 my_motor(PA_7, false); /*Instantiate a new OneSHot motor on pin PA_7 (0x07)*/
my_motor.stdSetPercent(50); /*Set the rotation speed at 50% of the max speed*/

```

### Bidirectionnal motor

__Work in process__

```
OneShot125 my_motor(PA_7, true); /*Instantiate a new OneShot motor on pin PA_7 (0x07)*/
my_motor.dualSetPercent(0, true); /*Set the rotation speed at 0%*/
my_motor.dualSetPercent(100, true); /*Set the rotation speed at 100% fwd*/
my_motor.dualSetPercent(100, false); /*Set the rotation speed at 100% reverse*/

```
