#include "quadtree_dec.h"

static void preencher(PGMDecImage *img, int x, int y, int s, unsigned char v) {
    for (int j = 0; j < s; j++) {
        for (int i = 0; i < s; i++) {
            img->data[(y + j) * img->width + (x + i)] = v;
        }
    }
}

static void dec_rec(BitStreamDec *bs, PGMDecImage *img, int x, int y, int s) {
    int bit = bsd_read_bit(bs);
    if (bit == 0) {
        unsigned char v = bsd_read_byte(bs);
        preencher(img, x, y, s, v);
        return;
    }

    int h = s / 2;

    dec_rec(bs, img, x,     y,     h);
    dec_rec(bs, img, x + h, y,     h);
    dec_rec(bs, img, x,     y + h, h);
    dec_rec(bs, img, x + h, y + h, h);
}

void quadtree_decode(BitStreamDec *bs, PGMDecImage *img) {
    dec_rec(bs, img, 0, 0, img->width);
}
