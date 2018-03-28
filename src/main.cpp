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
#include "ShiftREG.hpp"

typedef enum stateType_enum{
  shift, wait
} stateType;

volatile stateType state = shift;

volatile unsigned char data;
volatile unsigned char counter;



int main() {

  initTimer1();
  initSPI();
  initShiftREG();
  sei();//enable global interrupts

  //set slave select to low
  PORTB &= ~(1 << PORTB0); //starts the internal SPI clock

  //fill the SPDR register with something
  data = 0x42;
  SPDR = data;//just an arbitrary data value, it has no significance

  while(1){

    switch(state){
      case shift://update the data variable, changed in ISR
          state = wait;

          /*implement shift here and write the data*/

          break;
      case wait://waiting for the ISR
          break;

        }

  }

  return 0;
}

//SPI ISR - transmitting and receiving happens at the same time
ISR(SPI_STC_vect){
  //set SS high
  PORTB |= (1 << PORTB0);

  SPDR = data;//data being sent

  //set SS to low
  PORTB &= ~(1 << PORTB0);


  state = shift; //go to next state in State machine
  counter = (counter % 8) + 1;//this counter will be used to parse through the data in the state machine 

}
