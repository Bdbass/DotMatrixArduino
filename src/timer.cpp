#include "timer.hpp"
#include <avr/io.h>


/* Initialize timer 0, you should not turn the timer on here. You will need to
* use CTC mode
*/
void initTimer0(){
  TCCR0A |= (1 << WGM01); //sets it in CTC mode
}

void initTimer1(){
  // sets CTC Mode
  TCCR1B |= (1 << WGM12);

  // pre-scaler of 1024
  TCCR1B |= (1 << CS12) | (1 << CS10);

  // 1 ms timer (156.25) maybe 250
  // OCR1AL = 250;
  // OCR1AH = 0;
  OCR1A = 250;

  // enable interrupt
  TIMSK1 |= (1 << OCIE1A);
}

void delayUs(unsigned int delay){

  TCNT0 = 0;
  //puts flag down (if it wasnt already)
  TIFR0 |= (1 << OCF0A);

  TCCR0B &= ~((1 << CS02) | (1 << CS01)) ;
  TCCR0B |=  (1 << CS00); //prescalar of 1

  OCR0A = 16;

  for(unsigned int count = 0; count < delay; count++){

      while(!(TIFR0 & (1 << OCF0A)));//if it reaches on millisecond
        //TIFR0 &= ~(1 << OCF0A);//raises flag, idicating that its been the necessary time

        //puts flag down (if it wasnt already)
        TIFR0 |= (1 << OCF0A);

  }
}
