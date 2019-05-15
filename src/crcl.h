#ifndef CRCL_H
#define CRCL_H

#define N 200

typedef struct {
    double x;
    double y;
    double r;
    int ind;
} Crcl;

void circle(Crcl* in, int col);
int start(char* c, Crcl* in, int ind);
double perimetr(Crcl* in, int i);
double area(Crcl* in, int i);
int intersection(Crcl* in, int i, int j);
#endif
