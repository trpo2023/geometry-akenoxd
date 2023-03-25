#include "./check_error.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point {
    double x;
    double y;
};

struct circle {
    struct point point;
    double r;
};

int main(int argc, char** argv)
{
    struct circle* circle;
    int nCircle = 0;
    int code;
    float SR, D;
    double P, S;
    char str[100];
    FILE* data = argc > 1 ? fopen(argv[1], "r") : NULL;
    if (data == NULL) {
        printf("Error: incorrect file path, use ./app [FILE]\n");
        return 1;
    }

    while (fgets(str, 100, data) != NULL) {
        code = Check_Error(str);
        if (!code)
            continue;
        if (code) {
            nCircle++;
            circle = realloc(circle, nCircle * (sizeof(struct circle)));
            circle[nCircle - 1].point.x = strtod(strchr(str, '(') + 1, NULL);
            circle[nCircle - 1].point.y = strtod(strchr(str, ' ') + 1, NULL);
            circle[nCircle - 1].r = strtod(strchr(str, ',') + 1, NULL);
        }
    }
    printf("\n");
    for (int i = 0; i < nCircle; i++) {
        printf(" %d. circle(%.2lf %.2lf, %.2lf) \n",
               i + 1,
               circle[i].point.x,
               circle[i].point.y,
               circle[i].r);
        P = 2 * M_PI * circle[i].r;
        S = M_PI * circle[i].r * circle[i].r;
        printf("\tperimetr = %f\n", P);
        printf("\tarea = %f\n", S);
        printf("\tintersects: \n");
        for (int j = 0; j < nCircle; j++) {
            if (i == j)
                continue;
            SR = circle[i].r + circle[j].r;
            D
                    = sqrt(pow(circle[i].point.x - circle[j].point.x, 2)
                           + pow(circle[i].point.y - circle[j].point.y, 2));

            if (SR >= D)
                printf("\t  %d. circle \n", j + 1);
        }
        printf("\n");
    }
    free(circle);
    return 0;
}