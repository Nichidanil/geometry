#include "crcl.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int start(char* string, Crcl* in, int ind)
{
    // int i = 0;

    char circle[7] = {'c', 'i', 'r', 'c', 'l', 'e', '\0'};

    for (int i = 0; circle[i] != '\0'; i++) {
        if (string[i] != circle[i]) {
            printf("%d.String name Error\n", ind);
            return -1;
        }
    }
    int M = 200;

    char arr_x[M];
    char arr_y[M];
    char arr_r[M];

    if (string[6] != '(') {
        printf("%d.String breaker Error\n", ind);
        return -1;
    }
    if (string[7] < '0' || string[7] > '9') {
        printf("%d.String  y coord Error\n", ind);
        return -1;
    }

    int i = 7;
    for (int j = 0; string[i] != ' '; i++, j++) {
        arr_x[j] = string[i];
    }

    (in + ind)->x = atof(arr_x);
    i++;

    if (string[i] < '0' || string[i] > '9') {
        printf("%d.String coord Error\n", ind);
        return -1;
    }

    for (int j = 0; string[i] != ','; i++, j++) {
        if ((string[i] < '0' || string[i] > '9') && string[i] != '.') {
            printf("%d.String  y Error\n", ind);
            return -1;
        }
        arr_y[j] = string[i];
    }
    i += 2;
    (in + ind)->y = atof(arr_y);
    if (string[i] < '0' || string[i] > '9') {
        printf("%d.String Error\n", ind);
        return -1;
    }

    for (int j = 0; string[i] != ')'; i++, j++) {
        if (string[i] == '\0') {
            printf("%d.String breaker Error\n", ind);
            return -1;
        }
        if ((string[i] <= '0' || string[i] > '9') && string[i] != '.') {
            printf("%d.String coord r Error\n", ind);
            return -1;
        }
        arr_r[j] = string[i];
    }
    (in + ind)->r = atof(arr_r);
    return 0;
}

void circle(Crcl* in, int v)
{
    int inter;
    for (int i = 1; i < v; i++) {
        printf("%d.circle(%.4f %.4f, %.4f)\n",
               (in + i)->ind,
               (in + i)->x,
               (in + i)->y,
               (in + i)->r);
        printf("\tperimetr = %f\n", perimetr(in, i));
        printf("\tarea = %f\n", area(in, i));
        printf("\tinter: \n");
        for (int j = 1; j < v; j++) {
            inter = intersection(in, i, j);
            if (inter) {
                printf("\t\t%d. circle\n", (in + j)->ind);
            }
        }
    }
}

double perimetr(Crcl* in, int i)
{
    return (in + i)->r * 2 * M_PI;
}

double area(Crcl* in, int i)
{
    return (in + i)->r * (in + i)->r * M_PI;
}

int intersection(Crcl* in, int i, int j)
{
    double t;
    t
            = sqrt((double)pow((in + i)->x - (in + j)->x, 2.00)
                   + (double)pow((in + i)->y - (in + j)->y, 2.00));
    if (t < (in + i)->r + (in + j)->r && (in + i)->r < t + (in + j)->r
        && (in + j)->r < t + (in + i)->r) {
        return 1;
    }
    return 0;
}
