#include "../lib/bitstream.h"

void iniciarBitstream(struct bitstream *bs, FILE *f)
{
    bs->arquivo = f;
    bs->buffer = 0;
    bs->count = 0;
}

void escreverBit(struct bitstream *bs, unsigned char bit)
{
    bs->buffer <<= 1;
    
    if (bit)
    {
        bs->buffer |= 1;
    }
    
    bs->count++;

    if (bs->count == 8)
    {
        fwrite(&bs->buffer, sizeof(unsigned char), 1, bs->arquivo);
        bs->buffer = 0;
        bs->count = 0;
    }
}

void escreverByte(struct bitstream *bs, unsigned char byte)
{
    for (int i = 7; i >= 0; i--)
    {
        unsigned char bit = (byte >> i) & 1;
        escreverBit(bs, bit);
    }
}

void fecharBitstream(struct bitstream *bs)
{
    if (bs->count > 0)
    {
        bs->count <<= (8 - bs->count);

        fwrite(&bs->buffer, sizeof(unsigned char), 1, bs->arquivo);
    }
}