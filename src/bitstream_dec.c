#include "bitstream_dec.h"

BitStreamDec *bsd_open(const char *filename) {
    BitStreamDec *bs = (BitStreamDec *)malloc(sizeof(BitStreamDec));
    if (!bs) return NULL;

    bs->f = fopen(filename, "rb");
    if (!bs->f) {
        free(bs);
        return NULL;
    }

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
    if (bs->bit_pos == 0 || bs->bit_pos == 8) {
        int c = fgetc(bs->f);
        if (c == EOF) {
            bs->eof = 1;
            return 0;
        }
        return (unsigned char)c;
    }

    unsigned char b = 0;
    for (int i = 7; i >= 0; i--) {
        int bit = bsd_read_raw_bit(bs);
        b |= (bit << i);
    }
    return b;
}

void bsd_close(BitStreamDec *bs) {
    if (!bs) return;
    fclose(bs->f);
    free(bs);
}
