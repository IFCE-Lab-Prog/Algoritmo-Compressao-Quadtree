/***************************************************/
/* Aluno: Luiza Mel de Araujo Sobrinho */
/* Matrícula: 20251045050283 ∗/
/∗ Avaliação 04: Trabalho Final ∗/
/∗ 04.505.23 − 2025.2 − Prof. Daniel Ferreira ∗/
/∗ Compilador: gcc versão 13.3.0 ∗/
/***************************************************/

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
