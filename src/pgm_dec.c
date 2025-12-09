#include "../lib/pgm_dec.h"

PGMDecImage *pgm_dec_create(int size) {
    PGMDecImage *img = (PGMDecImage *)malloc(sizeof(PGMDecImage));
    if (!img) return NULL;

    img->width = size;
    img->height = size;
    img->data = (unsigned char *)malloc(size * size * sizeof(unsigned char));
    if (!img->data) {
        free(img);
        return NULL;
    }

    return img;
}

void pgm_dec_write(PGMDecImage *img, FILE *f) {
    fprintf(f, "P5\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, 1, img->width * img->height, f);
}

void pgm_dec_free(PGMDecImage *img) {
    if (!img) return;
    free(img->data);
    free(img);
}
