#include <stdio.h>

struct bitstream
{
    FILE *arquivo;
    unsigned char buffer;
    unsigned char count;
};

void iniciarBitstream(struct bitstream *, FILE *);
void lerBit(struct bitstream *);
void lerByte(struct bitstream *);
void fecharBitstream(struct bitstream *);