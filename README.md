# Hand Gesture Controlled Wheelchair
A completely wirelessly controllable wheelchair by using simple hand-gestures.

# Table of Contents

1. [Motivation](#motivation)  
2. [Description](#description)  
3. [Getting Started](#getting-started)
 
# Motivation

The goal of gesture recognition in Electronics field has always been the minimization of the distance between the physical world and the digital world.
Majority of the physically disabled and elderly people find it very tiring to control the traditional wheelchair and many a time need the assistance of another person. This projects aims at building a prototype model of a hand-gesture controlled wheelchair, thus making the wheelchair-bound completely independent and comfortable.

# Description
The prototype design contains two elementns, the Transmitter section containing the wristband and the Receiver section contaiting the wheelchair arrangement itself. The wristband arrangment is worn by the wheelchair bound and simple hand gestures like tilting of the band towards the right, left, up and downward directions are used to move the wheelchair. Additionally, an obstacle detection system is provided to ensure the safety of the user. The following sections give a deeper insight for the same.

## 1. Transmitter Section:

### 1.1. Components:
- Arduino Uno
- 434Mhz RF Transmitter
- ADXL335 Accelerometer
- 9V Battery Unit

### 1.2. Methodology
The ADXL335 is a MEMS(Micro-Electro-Mechanical Systems) Accelerometer which is a transducer that converts accelarations due to gravity into analog volatge outputs. The Arduino microcontroller is then coded to send messages that correspond to a certain hand gesture via the RF transmitter. 

## 2. Receiver Section:

### 2.1. Components:
- Arduino Uno
- 434Mhz RF Receiver
- Ultrasonic Sensor
- DC Motors and Wheels
- L293D Motor Driver IC
- Castor Wheel

### 2.2. Methodology
The RF receiver receives the messages via an RF antenna provides the data to the Arduino. The microcontroller is the programmed to decode the message and direct the direction of movement of the motors using the motor driver accordingly. 

# Getting Started
### Software and Library Installation
- Arduino IDE for coding.
- VirtualWire library for Wireless Communication.

### Steps to follow
1. Rig up the circuit as given in "accelerometer_uno_ckt.jpg" and make the wristband model with the position of accelerometer fixed permanently.
2. Next, in order to calibrate the accelerometer, dump the code given in "accelerometer_calibrate.ino" file onto the microcontroller.
3. Note down the voltage range for right, left, up and down (max tilt and min tilt) gestures.
4. After this, make additional connections as shown in "transmitter_section_ckt.jpg".
5. Dump the code given in "transmitter_section.ino" onto the same UNO.
6. Rig up the receiver circuit as given in "receiver_section_ckt.jpg"
7. Make necessary changes to the voltage ranges in the "receiver_section.ino" file and dump it onto the UNO placed on the wheelchair.
8. Finally, obstacle detection range can be altered in the "receiver_section.ino" as per requirements.


