#include "ShiftReg.hpp"
#include <avr/io.h>

void initShiftREG(){
    DDRL |= (1 << DDL0) | (1 << DDL2) | (1 << DDL4);  //setting SRCLR as output and setting OE as output
}

void shiftData(unsigned char character){
    unsigned char i;

    for (i = 0; i < 8; i++){
        if(character & (1 << (7 - i))){
            PORTB |= (1 << PORTB2);         //writing data 1
        }
        else{
            PORTB &= ~(1<< PORTB2);         //writing data 0
        }
        PORTB |= (1 << PORTB1);         //pulses the clock so data can be stored        note that we might need to delay in this piece
        PORTB &= ~(1<< PORTB1);
    }
}