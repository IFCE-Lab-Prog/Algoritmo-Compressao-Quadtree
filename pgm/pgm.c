#include <stdio.h>
#include <stdlib.h>
#include "../lib/pgm.h"

void readPGMImage(struct pgm *pio, char *filename)
{
	FILE *fp;
	char ch;

	if (!(fp = fopen(filename, "rb")))
    {
		perror("\nErro.\n");
		exit(1);
	}

	if ((ch = getc(fp)) != 'P')
    {
		puts("\nA imagem fornecida não está no formato pgm.");
		exit(2);
	}
	
	pio->tipo = getc(fp) - 48;
	
	fseek(fp, 1, SEEK_CUR);

	while((ch = getc(fp)) == '#')
    {
		while((ch = getc(fp)) != '\n');
	}

	fseek(fp, -1, SEEK_CUR);
	fscanf(fp, "%d %d", &pio->c, &pio->r);

	if (ferror(fp))
    { 
		perror(NULL);
		exit(3);
	}

	fscanf(fp, "%d", &pio->mv);
	fseek(fp, 1, SEEK_CUR);

	pio->pData = (unsigned char**) malloc(pio->r * sizeof(unsigned char *));

    if (pio->pData == NULL)
    {
        perror("\nErro ao alocar memória.\n");
        exit(4);
    }

    for (int i = 0; i < pio->r; i++)
    {
        *(pio->pData+i) = (unsigned char *) malloc(pio->c * sizeof(unsigned char));

        if (*(pio->pData+i) == NULL)
        {
            perror("\nErro ao alocar memória.\n");
            exit(5);
        }
    }

	switch(pio->tipo)
    {
        case 2:
            puts("\nLendo imagem PGM (dados em texto):");

            for (int i = 0; i < pio->r; i++)
            {
                for (int j = 0; j < pio->c; j++)
                {
                    fscanf(fp, "%hhu", &pio->pData[i][j]);
                }
            }

            break;
        case 5:
            puts("\nLendo imagem PGM (dados em binário):");

            for (int i = 0; i < pio->r; i++)
            {
                fread(pio->pData[i], sizeof(unsigned char), pio->c, fp);
            }

            break;
        default:
            puts("\nNão está implementado.");
    }
    
    fclose(fp);
}

void writePGMImage(struct pgm *pio, char *filename)
{
    FILE *fp;

    if (!(fp = fopen(filename, "wb")))
    {
        perror("\nErro.\n");
        exit(1);
    }

    fprintf(fp, "P5\n");
    fprintf(fp, "%d %d\n", pio->c, pio->r);
    fprintf(fp, "%d\n", 255);

    for (int i = 0; i < pio->r; i++)
    {
        fwrite(pio->pData[i], sizeof(unsigned char), pio->c, fp);
    }

    fclose(fp);
}

void viewPGMImage(struct pgm *pio)
{
    printf("Tipo: %d\n", pio->tipo);
    printf("Dimensões: [%d %d]\n", pio->c, pio->r);
    printf("Max: %d\n", pio->mv);

    for (int i = 0; i < pio->r; i++)
    {
        for (int j = 0; j < pio->c; j++)
        {
            printf("%2hhu ", pio->pData[i][j]);
        }

        printf("\n");
    }
    
    printf("\n");
}