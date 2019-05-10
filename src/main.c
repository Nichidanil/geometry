#include "crcl.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char c[N];

    FILE* gm;
    gm = fopen("in.txt", "r");

    if (gm == NULL) {
        printf("Error\n");
        return -1;
    }

    Crcl* in = (Crcl*)malloc(sizeof(Crcl) * N);

    int v = 0;

    while (!feof(gm)) {
        fgets(c, N, gm);
        if (strcmp(c, "\n\0") == 0) {
            continue;
        }

        v++;
        (in + v)->ind = v;

        if (start(c, in, v) == -1) {
            v--;
            continue;
        }
    }
    // printf("What is contained: %s\n",c);
    circle(in, v);
    fclose(gm);

    return 0;
}
