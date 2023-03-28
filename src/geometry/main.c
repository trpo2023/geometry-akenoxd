#include <check_error.h>
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

int intersect(struct circle circle1, struct circle circle2)
{
    double SR, D;
    SR = circle1.r + circle2.r;
    D
            = sqrt(pow(circle1.point.x - circle2.point.x, 2)
                   + pow(circle1.point.y - circle2.point.y, 2));
    if (SR >= D)
        return 1;
    else
        return 0;
}

float Circle_area(double radius)
{
    return M_PI * radius * radius;
}
float Circle_perimeter(double radius)
{
    return 2 * M_PI * radius;
}

int main(int argc, char** argv)
{
    struct circle* circle;
    int nCircle = 0;
    int code;
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
        printf("\tperimetr = %f\n", Circle_perimeter(circle[i].r));
        printf("\tarea = %f\n", Circle_area(circle[i].r));
        printf("\tintersects: \n");
        for (int j = 0; j < nCircle; j++) {
            if (i == j)
                continue;
            if (intersect(circle[i], circle[j]))
                printf("\t  %d. circle \n", j + 1);
        }
        printf("\n");
    }
    free(circle);
    return 0;
}