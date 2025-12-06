#include <stdio.h>
#include "../lib/bitstream.h"

void iniciarBitstream(struct bitstream *bs, FILE *f)
{
    bs->arquivo = f;
    bs->buffer = 0;
    bs->count = 0; 
    
    if (fread(&bs->buffer, sizeof(unsigned char), 1, bs->arquivo) == 1){
        bs->count = 8; 
    }
}

int lerBit(struct bitstream *bs)
{
    if (bs->count == 0)
    {
        if (fread(&bs->buffer, sizeof(unsigned char), 1, bs->arquivo) != 1)
        {
            return -1;
        }
        bs->count = 8;
    }
    
    unsigned char bit = (bs->buffer >> (bs->count - 1)) & 1;
    bs->count--;
    return (int)bit;
}

int lerByte(struct bitstream *bs)
{
    unsigned char byte = 0;
    
    for (int i = 0; i < 8; i++)
    {
        int bit = lerBit(bs);
        
        if (bit == -1)
        {
            return -1;
        }
        byte = (byte << 1) | bit;
    }
    
    return byte;
}

void fecharBitstream(struct bitstream *bs)
{
    fclose(bs->arquivo);
}