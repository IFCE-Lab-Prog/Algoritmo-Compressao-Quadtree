#include "../lib/quadtree_dec.h"

static void preencher(PGMDecImage *img, int x, int y, int s, unsigned char v) {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            img->data[(x + i) * img->width + (y + j)] = v;
        }
    }
}

static void dec_rec(BitStreamDec *bs, PGMDecImage *img, int x, int y, int s) {
    if (s < 1) return;
    int bit = bsd_read_bit(bs);
    if (bit == 0) {
        unsigned char v = bsd_read_byte(bs);
        preencher(img, x, y, s, v);
        return;
    }

    int h = s / 2;

    dec_rec(bs, img, x,     y,     h);
    dec_rec(bs, img, x,     y + h,     h);
    dec_rec(bs, img, x + h,     y, h);
    dec_rec(bs, img, x + h, y + h, h);
}

void quadtree_decode(BitStreamDec *bs, PGMDecImage *img) {
    dec_rec(bs, img, 0, 0, img->width);
}
