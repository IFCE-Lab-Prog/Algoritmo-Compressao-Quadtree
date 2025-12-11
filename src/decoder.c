/***************************************************/
/* Aluno: Larissa Gabriela Garcia da Silva */
/* Matrícula: 20251045050232 ∗/
/∗ Avaliação 04: Trabalho Final ∗/
/∗ 04.505.23 − 2025.2 − Prof. Daniel Ferreira ∗/
/∗ Compilador: gcc versão 13.3.0 ∗/
/***************************************************/

#include "../lib/decoder.h"
#include "../lib/bitstream_dec.h"
#include "../lib/pgm_dec.h"
#include "../lib/quadtree_dec.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("\nUso:\n\t %s <entrada.bin> <saida.pgm>\n\n", argv[0]);
        return 1;
    }

    FILE *fbin = fopen(argv[1], "rb");
    if (!fbin) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    unsigned short int size;

    fread(&size, sizeof(unsigned short int), 1, fbin);

    BitStreamDec *bs = bsd_create(fbin);
    if (!bs) {
        fclose(fbin);
        return 1;
    }

    PGMDecImage *img = pgm_dec_create(size);
    if (!img) {
        bsd_close(bs);
        fclose(fbin);
        return 1;
    }

    quadtree_decode(bs, img);

    bsd_close(bs);
    fclose(fbin);

    FILE *fpgm = fopen(argv[2], "wb");
    if (!fpgm) {
        pgm_dec_free(img);
        return 1;
    }

    pgm_dec_write(img, fpgm);

    fclose(fpgm);

    pgm_dec_free(img);

    return 0;
}
