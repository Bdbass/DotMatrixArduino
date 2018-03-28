#include "SPI.hpp"
#include <avr/io.h>

void initSPI(){

//set SS, MOSI, and SCLK pin as output (PCINT 0-3, PB 0-3)
DDRB |= (1 << DDB0) | (1 << DDB1) | (1 << DDB2);

//set SS high at first
PORTB |= (1 << PORTB0);

//enable the interrupt, SPI, mastermode, default clock, and fosc/128
SPCR |= (1 << SPIE) | (1 << SPE) | (1 << MSTR)| (1 << SPR1) | (1 << SPR0);
}
