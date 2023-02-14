#include <ctype.h>
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

struct triangle {
    struct point A;
    struct point B;
    struct point C;
};
int Check_Error(char* str)
{
    if (!(strncmp("circle", str, 6))) {
        if (!(isdigit(*strchr(str, '(')))) {
            printf("%s", str);
            for (int i = 0; i < strchr(str, '(') - &str[0] + 1; i++)
                printf(" ");
            printf("^\n");
            printf("Error at column %ld: expected \'double\'\n\n",
                   strchr(str, '(') - &str[0] + 1);
        }
        if (strtod(strchr(str, ',') + 1, NULL) <= 0) {
            printf("%s", str);
            for (int i = 0; i < strchr(str, ',') - &str[0] + 2; i++)
                printf(" ");
            printf("^\n");
            printf("Error at column %ld: radius cant be \'0\' or "
                   "negative "
                   "value\n\n",
                   strchr(str, ',') - &str[0] + 2);
            return 0;
        } else
            return 1;
    } else if (!(strncmp("triangle", str, 8))) {
        return 2;
    } else if (!(strncmp("polygon", str, 7))) {
        return 3;
    } else {
        printf("%s \n^\n", str);
        printf("Eror at column 0: expected \'circle\', \'triangle\' or "
               "\'polygon\'\n\n");
        return 0;
    }
}

int main(int argc, char** argv)
{
    struct circle* circle;
    struct triangle* triangle;
    int nCircle = 0, nTriangle = 0, nPolygon = 0;
    int n = 0, code;
    int SR, D;
    double P, S;
    char str[100];
    FILE* data = argc > 1 ? fopen(argv[1], "r") : stdin;
    if (data == NULL) {
        printf("Error: file not found\n");
        return 1;
    }

    while (fgets(str, 100, data) != NULL) {
        n = nCircle + nTriangle + nPolygon;
        code = Check_Error(str);
        if (!code)
            continue;
        if (code == 1) {
            nCircle++;
            circle = realloc(circle, nCircle * (sizeof(struct circle)));
            circle[nCircle - 1].point.x = strtod(strchr(str, '(') + 1, NULL);
            circle[nCircle - 1].point.y = strtod(strchr(str, ' ') + 1, NULL);
            circle[nCircle - 1].r = strtod(strchr(str, ',') + 1, NULL);
        } else if (code == 2) {
            nTriangle++;
            triangle = realloc(triangle, nTriangle * (sizeof(struct triangle)));
            triangle[nTriangle - 1].A.x = strtod(strchr(str, '(') + 2, NULL);
            triangle[nTriangle - 1].A.y = strtod(strchr(str, ' ') + 1, NULL);
            for (int i = 0; i < strchr(str, ',') - str; i++) {
                str[i] = ' ';
                n = i;
            }
            str[n + 1] = ' ';
            triangle[nTriangle - 1].B.x = strtod(strchr(str, ',') + 1, NULL);
            triangle[nTriangle - 1].B.y = strtod(strchr(str, ' ') + 1, NULL);
            for (int i = 0; i < strchr(str, ',') - &str[0]; i++) {
                str[i] = ' ';
                n = i;
            }
            str[n + 1] = ' ';
            triangle[nTriangle - 1].C.x = strtod(strchr(str, ',') + 1, NULL);
            triangle[nTriangle - 1].C.y = strtod(strchr(str, ' ') + 1, NULL);
        } else if (code == 3) {
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
    for (int i = 0; i < nTriangle; i++) {
        printf(" %d. triangle(%.2lf %.2lf, %.2lf %.2lf, %.2lf %.2lf) \n",
               i + 1,
               triangle[i].A.x,
               triangle[i].A.y,
               triangle[i].B.x,
               triangle[i].B.y,
               triangle[i].C.x,
               triangle[i].C.y);
    }
    return 0;
    free(circle);
    free(triangle);
}