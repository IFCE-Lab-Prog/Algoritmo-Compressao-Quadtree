#include "../lib/compress.h"
#include "../lib/util.h"

#define LIMIAR 4.5

void codificador_quadtree(unsigned char **image, int x, int y, int size, struct bitstream *bs)
{
    if (calcular_desvio_padrao(image, x, y, size) <= LIMIAR || size == 1)
    {
        escreverBit(bs, 0);
        escreverByte(bs, calcular_media(image, x, y, size));
    }
    else
    {
        escreverBit(bs, 1);
        size = size/2;

        codificador_quadtree(image, x, y, size, bs);
        codificador_quadtree(image, x, y + size, size, bs);
        codificador_quadtree(image, x + size, y, size, bs);
        codificador_quadtree(image, x + size, y + size, size, bs);
    }
}