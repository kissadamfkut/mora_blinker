Mora-blinker
========== 
## Goals
  
- Provide a simple and cheap educational embedded project
- Demonstrate basic electric design 
- Demonstrate both C++ basics and advanced tricks
- More entertaining first program than a 'Hello world'
- Educate for software design in low-end environments

## How to use

- The schematics and the PCB board can be found in the hw folder. You can open the files with KiCAD 6
- The software is in the sw folder. Do not forget to also pull the git submodules!
- The build environment for the software includes avr-gcc 11.2, avrdude 6.4 and make 4.3
- Do not connect the battery when using a 5V ISP!
- After building the PCB, connect an STK500 or similar, and type ```make program```
- You can switch animations with the reset button

## Bill of materials

- CR2032 holder
- CR2032
- 100 nF capacitor
- Yellow LEDs (x5)
- 120 ohm resistors (x5)
- 9.1 kohm resistor
- Button
- ATtiny13A

## Theory of operation

The timer overflow interrupt drives a soft-PWM routine. The running animation changes an array of the LEDs' duty cycles. Resetting the device, the content of the SRAM is not random, so the index of the last animation is known, except for the cold-start, when it is random (not a problem). Some data is stored in the EEPROM to save space.
   
## Known issues  
  
- Fuse calculation could be more describing
- May further optimize base code
- Less numeric constant

## Work of a student

![](pcb.jpg)
