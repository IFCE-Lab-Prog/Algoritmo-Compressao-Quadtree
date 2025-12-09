/***************************************************/
/* Aluno: Daniel Freitas da Silva */
/* Matrícula: 20251045050593 ∗/
/∗ Avaliação 04: Trabalho Final ∗/
/∗ 04.505.23 − 2025.2 − Prof. Daniel Ferreira ∗/
/∗ Compilador: gcc versão 13.3.0 ∗/
/***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "../lib/compress.h"
#include "../lib/binHeader.h"

int main(int argc, char *argv[])
{
    struct pgm img;

	if (argc != 3)
    {
		printf("\nFormato: \n\t%s <imagemEntrada.pgm> <arquivoSaida.bin>\n\n", argv[0]);
		exit(1);
	}

	readPGMImage(&img, argv[1]);

    FILE *arquivoSaida;
    
    if (!(arquivoSaida = fopen(argv[2], "wb")))
    {
        perror("\nErro.\n");
		exit(2);
    }

    struct binHeader bh;

    writeBINHeader(&img, &bh, arquivoSaida);

    struct bitstream bs;

    iniciarBitstream(&bs, arquivoSaida);

    codificador_quadtree(img.pData, 0, 0, img.r, &bs);

    fecharBitstream(&bs);

    fclose(arquivoSaida);

    for (int i = 0; i < img.r; i++)
    {
        free(*(img.pData+i));
    }

    free(img.pData);

	return 0;
}