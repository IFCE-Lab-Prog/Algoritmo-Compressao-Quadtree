#include <stdio.h>
#include "pgm.h"

struct binHeader
{
    char assinatura[2];
    unsigned short c;
    unsigned short r;
    unsigned char mv;
};

void writeBINHeader(struct pgm *, struct binHeader *, FILE *);