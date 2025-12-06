#include <stdio.h>
#include <stdlib.h>
#include "../lib/pgm.h"
#include "../lib/bitstream.h"
#include "../lib/compress.h"

int main(int argc, char *argv[])
{
    struct pgm img;

	if (argc != 3)
    {
		printf("\nFormato: \n\t%s <imagemEntrada.pgm> <arquivoSaida.bin>\n", argv[0]);
		exit(1);
	}

	readPGMImage(&img, argv[1]);

    FILE *arquivoSaida;

    if (!(arquivoSaida = fopen(argv[2], "wb")))
    {
        perror("\nErro.\n");
		exit(2);
    }

    struct bitstream bs;

    iniciarBitstream(&bs, arquivoSaida);

    fecharBitstream(&bs);

    fclose(arquivoSaida);

	return 0;
}