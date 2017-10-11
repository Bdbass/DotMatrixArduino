Course Name: ece372a-online <br>
Authors: <br>
NetIDs: <br>
Date: <br>
Project Name: lab6

# Description
In this lab, you will work in a ** team ** . Since this is the case, the code given to you is extremely minimal. You will work together to control an LED dot matrix through two shift registers.

## Expected Outcome
# Instructions
You are given a boiler-plate main.cpp function. You and your team must create other necessary source and header files with functions that fulfill the overall requirements.

# Group Requirements
## Overall
1. The project must be pushed to GitLab and an appropriate response from the server must be received: "Got your submission. Thanks!" This can be one repository per team
2. Every file must contain code related to a single device. For example, the SPI and Timer code must be separated. The main function is an exception.
3. The dot-matrix must show a letter that cycles across the dot matrix. Orientation is not that important here.
4. There are no non-trivial SFR manipulations in the main function and are wrapped in functions that have meaningful names
5. SPI is used to control two shift registers
6. A state machine is used to implement the bulk of the functionality of the program

# Individual Requirements
Each person in the group should be assigned a part of the lab. These correspond to the individual requirements.

## SPI, Shift Register
1. A function exists to initialize the SPI module
2. The MOSI, SCK, SS pins are set to outputs
3. The SPI is initialized with its interrupt enabled, in master mode, and the oscillator configured to have a prescaler of 128
4. The SPI state machine appears to at least be able to correctly send 8 bits and stop. This can be verified with the oscilloscope.


## Shift Register
1. The SPI module can be used to output an arbitrary unsigned char to the shift register and this functionality can be verified with the dot-matrix or several LCDs.
2. Two shift registers are chained together to be able to output and arbitrary 16 bit number. This can be verified with the dot-matrix or LEDs
3. PORTL0 and PORTL2 are connected to the shift register SRCLR pin to clear previous stored data if necessary.
4. PORTL4 is connected to both shift register's OE pin.
5. The SCK pin of the SPI module is used as both the RCLK and SRCLK inputs
6. The MOSI pin of the SPI module is used as the SER input

## Timer 1, Dot Matrix
1. Timer 1 is correctly configured to provide a precise microsecond delay capable of delaying up to at least 10,000  microseconds.
2. The dot matrix can correctly show a letter on the screen using simple digital I/O

# Rubric
![Lab 6](https://storage.googleapis.com/ece-gitlab/group-lab-rubric)
