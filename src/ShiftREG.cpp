#include "ShiftReg.hpp"
#include <avr/io.h>

void initShiftREG(){
    DDRL |= (1 << DDL0) | (1 << DDL2) | (1 << DDL4);  //setting SRCLR as out but and setting OE as output
}