/***************************************************/
/* Aluno: Luiza Mel de Araujo Sobrinho */
/* Matrícula: 20251045050283 ∗/
/∗ Avaliação 04: Trabalho Final ∗/
/∗ 04.505.23 − 2025.2 − Prof. Daniel Ferreira ∗/
/∗ Compilador: gcc versão 13.3.0 ∗/
/***************************************************/

#include "../lib/bitstream_dec.h"

BitStreamDec *bsd_create(FILE *f) {
    BitStreamDec *bs = (BitStreamDec *)malloc(sizeof(BitStreamDec));
    if (!bs) return NULL;

    
    bs->f = f;
    bs->buffer = 0;
    bs->bit_pos = 8;
    bs->eof = 0;

    return bs;
}

static int bsd_read_raw_bit(BitStreamDec *bs) {
    if (bs->bit_pos == 8) {
        int c = fgetc(bs->f);
        if (c == EOF) {
            bs->eof = 1;
            return 0;
        }
        bs->buffer = (unsigned char)c;
        bs->bit_pos = 0;
    }

    int bit = (bs->buffer >> (7 - bs->bit_pos)) & 1;
    bs->bit_pos++;
    return bit;
}

int bsd_read_bit(BitStreamDec *bs) {
    if (bs->eof) return 0;
    return bsd_read_raw_bit(bs);
}

unsigned char bsd_read_byte(BitStreamDec *bs) {
    unsigned char b = 0;
    for (int i = 7; i >= 0; i--) {
        int bit = bsd_read_raw_bit(bs);
        b |= (bit << i);
    }
    return b;
}

void bsd_close(BitStreamDec *bs) {
    if (!bs) return;
    free(bs);
}
