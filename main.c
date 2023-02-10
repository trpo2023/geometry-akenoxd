#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pi 3.14159

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
    int nCircle = 0, nTriangle = 0, nPolygon = 0;
    int n = 0;
    int SR, D;
    double P, S;
    char str[100];
    FILE* data = argc > 1 ? fopen(argv[1], "r") : stdin;
    if (data == NULL) {
        printf("Error opening file");
        return 1;
    }

    while (fgets(str, 100, data) != NULL) {
        n = nCircle + nTriangle + nPolygon;
        if (!(strncmp("circle", str, 6))) {
            nCircle++;
            circle = realloc(circle, nCircle * (sizeof(struct circle)));
            circle[nCircle - 1].point.x = strtod(strchr(str, '(') + 1, NULL);
            circle[nCircle - 1].point.y = strtod(strchr(str, ' ') + 1, NULL);
            circle[nCircle - 1].r = strtod(strchr(str, ',') + 1, NULL);

        } else if (!(strncmp("triangle", str, 8))) {
            nTriangle++;
            continue;
        } else if (!(strncmp("polygon", str, 7))) {
            nPolygon++;
            continue;
        } else {
            printf("%s \n^\n", str);
            printf("Eror at column 0: expected \'circle\', \'triangle\' or "
                   "\'polygon\'\n\n");
            continue;
        }
    }

    for (int i = 0; i < nCircle; i++) {
        printf(" %d. circle(%.2lf %.2lf, %.2lf) \n",
               i + 1,
               circle[i].point.x,
               circle[i].point.y,
               circle[i].r);
        P = 2 * pi * circle[i].r;
        S = pi * circle[i].r * circle[i].r;
        printf("\tperimetr = %f\n", P);
        printf("\tarea = %f\n", S);
        printf("\tintersects: \n");
        for (int j = 0; j < nCircle - 1; j++) {
            if (i == j)
                continue;
            SR = circle[j].r + circle[j + 1].r;
            D
                    = sqrt(pow(circle[i].point.x - circle[j].point.x, 2)
                           + pow(circle[i].point.y - circle[j].point.y, 2));
            if (SR >= D)
                printf("\t  %d. circle \n", j + 1);
        }
        printf("\n");
    }
    return 0;
    free(circle);
}