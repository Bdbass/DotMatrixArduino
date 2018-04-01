#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "SPI.hpp"
#include "DotMatrix.hpp"
#include "ShiftREG.hpp"
#include "timer.hpp"



typedef enum stateType_enum{
  shift, wait
} stateType;

volatile stateType state = shift;
volatile int shift_delay = 1;
volatile int count = 0;


int main(){

  initSPI();
  sei();
  initShiftREG();
  PORTB &= ~(1 << PORTB0); //changed
  SPDR = 0x00;
  int last;

  while(1){

    switch(state){
      case shift://update the data variable, changed in ISR
      last = columnValues[7];          // save off first element
      // shift right
      for(int i = 6; i >= 0 ; i-- )columnValues[i+1] = columnValues[i];
          // wrap last element into first slot
          columnValues[0] = last;

          state = wait;
          break;
      case wait://waiting for the ISR
          break;

        }
  }
  return 0;
}




ISR(SPI_STC_vect){

  PORTB |= (1 << PORTB0);// slave select high
  PORTL &= ~(1 << DDL0 | 1 << DDL2); // puts latch down so we can send data and resets data so we dont get flashing
  PORTL |= (1 << DDL2); // pulls the clear  high so we can actually get data

  SPDR = columnValues[count]; // sends data
  while (!(SPSR & (1 << SPIF))); // waits for data to be sent low
  PORTL |= (1 << DDL0); // put latch high to prevent overflow

  delayUs(1);//_delay_ms(1);

  PORTL &= ~(1 << DDL0); // latch low again
  SPDR = dataValues[count]; // sends data
  while (!(SPSR & (1 << SPIF))); // waits for data
  PORTL |= (1 << DDL0) | (1 << DDL2); // latch high again

  PORTB &= ~(1<<PORTB0); // slave select low
  //SPCR &= ~(1 << SPIE); // turn off ISR used for debugging
  count = ++count%8;
  delayUs(2);//_delay_ms(2);


  shift_delay++;
  if (shift_delay == 1024){
    state = shift;
    shift_delay = 1;
  }
}
