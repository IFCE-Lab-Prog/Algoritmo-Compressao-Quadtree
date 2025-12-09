/***************************************************/
/* Aluno: Daniel Freitas da Silva */
/* Matrícula: 20251045050593 ∗/
/∗ Avaliação 04: Trabalho Final ∗/
/∗ 04.505.23 − 2025.2 − Prof. Daniel Ferreira ∗/
/∗ Compilador: gcc versão 13.3.0 ∗/
/***************************************************/

#include "../lib/binHeader.h"

void writeBINHeader(struct pgm *image, struct binHeader *header, FILE *arquivo)
{
    header->assinatura[0] = 'B';
    header->assinatura[1] = 'S';
    header->c = (unsigned short) image->c;
    header->r = (unsigned short) image->r;
    header->mv = (unsigned char) image->mv;

    fprintf(arquivo, "%c%c\n%d %d\n%d\n", header->assinatura[0], header->assinatura[1], header->c, header->r, header->mv);
}