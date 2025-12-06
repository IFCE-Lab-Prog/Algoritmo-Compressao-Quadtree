#include <math.h>
#include "../lib/util.h"

double calcular_media(unsigned char **image, int x, int y, int size)
{
    unsigned long soma = 0;
    int i, j;
    int numpixel = size * size;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            soma += image[x + i][y + j];
        }
    }

    return (((double) soma) / numpixel);
}

double calcular_desvio_padrao(unsigned char **image, int x, int y, int size)
{
    double media = calcular_media(image, x, y, size);
    double variancia = 0.0;
    int i, j;
    int numpixel = size * size;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            variancia += pow(((double) image[x + i][y + j]) - media, 2);
        }
    }

    variancia /= numpixel;

    return sqrt(variancia);
}