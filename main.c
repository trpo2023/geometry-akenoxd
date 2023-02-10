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
    int i = 1;
    int n, SR, D;
    double P, S;
    char str[100];
    FILE* data = argc > 1 ? fopen(argv[1], "r") : stdin;
    if (data == NULL) {
        printf("Error opening file");
        return 1;
    }
    fscanf(data, "%d\n", &n);
    struct circle* circle = malloc(sizeof(*circle) * n);
    while (fgets(str, 100, data) != NULL) {
        circle[i - 1].point.x = strtod(strchr(str, '(') + 1, NULL);
        circle[i - 1].point.y = strtod(strchr(str, ' ') + 1, NULL);
        circle[i - 1].r = strtod(strchr(str, ',') + 1, NULL);
        i++;
    }
    for (int i = 0; i < n; i++) {
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
        for (int j = 0; j < n - 1; j++) {
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