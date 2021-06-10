# Gas Dectector in C++

## What it is

This project contains:
-the gas Sensor(MQ-2 Gas Sensor) senses gas exposed in the environment.
-the buzzer immediately gives an audible bip for some seconds and then buzzes continually in the presence of gas
- the Liquid Crystal Display(LCD) visually notify users of alerts.
-the LCD also display when the environment of the users is safe(i.e when no gas is detected).




## Hardware requirements


Sensor | Pin
--- | ---
Gas Sensor|A1
Buzzer | 6
LCD | 8

*Jumper wires
*220 Ohms resistor
*Arduino UNO R3 

## Software requirements

1. Arduino IDE(We use the arduino IDE to compile our code and upload to the Arduino UNO )
2.Tinkercad(a Web appilication that simulates our project using the source code)
Image of simulation![Screenshot (102)](https://user-images.githubusercontent.com/83757220/121539084-df455c00-c9f4-11eb-8b11-aca7379bb378.png)
Link to simulation:https://www.tinkercad.com/things/5K7lRwhfJxj-project-work/editel?sharecode=XvTkJMTq0vw2VRDFVeiPVesGfoL2fBa1Z9DTeqxHjuA
This link references the libraries,function, structures and variables used in the code.
https://www.arduino.cc/reference/en/
Such as the 
Liquid Crystal Display Library:
This library allows an Arduino board to control Liquid Crystal displays (LCDs) based on the Hitachi HD44780 (or a compatible) chipset, which is found on most text-based LCDs. The library works with in either 4- or 8-bit mode.

