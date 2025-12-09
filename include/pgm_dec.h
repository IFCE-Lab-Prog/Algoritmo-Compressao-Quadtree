#ifndef PGM_DEC_H
#define PGM_DEC_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} PGMDecImage;

PGMDecImage *pgm_dec_create(int size);
void pgm_dec_write(PGMDecImage *img, const char *filename);
void pgm_dec_free(PGMDecImage *img);

#endif
