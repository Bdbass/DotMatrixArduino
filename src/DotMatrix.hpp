#ifndef DOTMATRIX_H
#define DOTMATRIX_H

volatile int dataValues[] = {
  0b01111110,
  0b01111110,
  0b11111111,//blank
  0b10111101,
  0b11111111,//blank
  0b11011011,
  0b11111111,//blank
  0b11100111
};

volatile int columnValues[] = {
  0b00000001,
  0b00000010,
  0b00000100,//blank
  0b00001000,
  0b00010000,//blank
  0b00100000,
  0b01000000,//blank
  0b10000000
};

#endif
