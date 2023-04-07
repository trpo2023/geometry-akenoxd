#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <calcul.h>
#include <check_error.h>
#include <print_error.h>

struct point {
    double x;
    double y;
};

struct circle {
    struct point point;
    double r;
};

void print_result(struct circle* circle, int nCircle)
{
    for (int i = 0; i < nCircle; i++) {
        printf(" %d. circle(%.2lf %.2lf, %.2lf) \n",
               i + 1,
               circle[i].point.x,
               circle[i].point.y,
               circle[i].r);
        printf("\tperimetr = %.2f\n", Circle_perimeter(circle[i].r));
        printf("\tarea = %.2f\n", Circle_area(circle[i].r));
        printf("\tintersects: \n");
        for (int j = 0; j < nCircle; j++) {
            if (i == j)
                continue;
            if (intersect(
                        circle[i].point.x,
                        circle[i].point.y,
                        circle[j].point.x,
                        circle[j].point.y,
                        circle[i].r,
                        circle[j].r))
                printf("\t  %d. circle \n", j + 1);
        }
        printf("\n");
    }
}

int main(int argc, char** argv)
{
    struct circle* circle;
    int nCircle = 0;
    char str[100];
    FILE* data = argc > 1 ? fopen(argv[1], "r") : NULL;
    if (data == NULL) {
        printf("Error: incorrect file path, use ./app [FILE]\n");
        return 1;
    }

    while (fgets(str, 100, data) != NULL) {
        if (Check_Error(str)) {
            Print_Error(str, Check_Error(str));
            continue;
        } else {
            nCircle++;
            circle = realloc(circle, nCircle * (sizeof(struct circle)));
            circle[nCircle - 1].point.x = strtod(strchr(str, '(') + 1, NULL);
            circle[nCircle - 1].point.y = strtod(strchr(str, ' ') + 1, NULL);
            circle[nCircle - 1].r = strtod(strchr(str, ',') + 1, NULL);
        }
    }
    printf("\n");
    print_result(circle, nCircle);
    free(circle);
    return 0;
}