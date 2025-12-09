#include <stdio.h>
#include "pgm.h"

struct binHeader
{
    char assinatura[2];
    int c;
    int r;
    unsigned char mv;
};

void writeBINHeader(struct pgm *, struct binHeader *, FILE *);
