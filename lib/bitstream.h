#include <stdio.h>

struct bitstream
{
    FILE *arquivo;
    unsigned char buffer;
    unsigned char count;
};

void iniciarBitstream(struct bitstream *, FILE *);
void escreverBit(struct bitstream *, unsigned char);
void escreverByte(struct bitstream *, unsigned char);
void fecharBitstream(struct bitstream *);