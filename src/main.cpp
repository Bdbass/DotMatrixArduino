// Author:
// Net ID:
// Date:
// Assignment:
//
// Description: File description
//----------------------------------------------------------------------//
#include <avr/io.h>
#include <avr/interrupt.h>
#include "SPI.hpp"
#include "timer.hpp"




int main() {

  initTimer1();
  initSPI();
  sei();//enable global interrupts

  //set slave select to low
  PORTB &= ~(1 << PORTB0); //starts the internal SPI clock

  //fill the SPDR register with something
  SPDR = 'V';//just an arbitrary data value, it has no significance

  while(1){

  }

  return 0;
}

//SPI ISR - transmitting and receiving happens at the same time
ISR(SPI_STC_vect){
  //set SS high
  PORTB |= (1 << PORTB0);

  SPDR = 'V';//data being sent

  //set SS to low
  PORTB &= ~(1 << PORTB0);

}
