#ifndef BITSTREAM_DEC_H
#define BITSTREAM_DEC_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE *f;
    unsigned char buffer;
    int bit_pos;
    int eof;
} BitStreamDec;

BitStreamDec *bsd_create(FILE *f);
int bsd_read_bit(BitStreamDec *bs);
unsigned char bsd_read_byte(BitStreamDec *bs);
void bsd_close(BitStreamDec *bs);

#endif
