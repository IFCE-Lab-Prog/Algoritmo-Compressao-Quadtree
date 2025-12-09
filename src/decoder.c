#include "decoder.h"
#include "bitstream_dec.h"
#include "pgm_dec.h"
#include "quadtree_dec.h"

int main(int argc, char **argv) {
    if (argc < 3) {
        return 1;
    }

    BitStreamDec *bs = bsd_open(argv[1]);
    if (!bs) {
        return 1;
    }

    int high = bsd_read_byte(bs);
    int low = bsd_read_byte(bs);
    int size = (high << 8) | low;

    PGMDecImage *img = pgm_dec_create(size);
    if (!img) {
        bsd_close(bs);
        return 1;
    }

    quadtree_decode(bs, img);

    pgm_dec_write(img, argv[2]);

    pgm_dec_free(img);
    bsd_close(bs);

    return 0;
}
