#include <calcul.h>
#include <check_error.h>
#include <stdio.h>
#include <string.h>

struct point {
    double x;
    double y;
};

struct circle {
    struct point point;
    double r;
};

void Print_Error(char* str, int n)
{
    if (n == 1) {
        printf("%s", str);
        for (int i = 0; i < strchr(str, '(') - &str[0] + 1; i++)
            printf(" ");
        printf("^\n");
        printf("Error at column %ld: expected \'double\'\n\n",
               strchr(str, '(') - &str[0] + 1);
        return;
    } else if (n == 2) {
        printf("%s", str);
        for (int i = 0; i < (strchr(str, ' ') - &str[0] + 1); i++)
            printf(" ");
        printf("^\n");
        printf("Error at column %ld: expected \'double\'\n\n",
               strchr(str, ' ') - &str[0] + 1);
        return;
    } else if (n == 3) {
        printf("%s", str);
        for (int i = 0; i < (strchr(str, ',') - &str[0] + 2); i++)
            printf(" ");
        printf("^\n");
        printf("Error at column %ld: expected \'double\'\n\n",
               strchr(str, ',') - &str[0] + 1);
        return;
    } else if (n == 4) {
        printf("%s", str);
        for (int i = 0; i < strchr(str, ',') - &str[0] + 2; i++)
            printf(" ");
        printf("^\n");
        printf("Error at column %ld: radius cant be \'0\' or "
               "negative "
               "value\n\n",
               strchr(str, ',') - &str[0] + 2);
        return;
    } else if (n == 5) {
        printf("%s", str);
        printf("^\n");
        printf("Eror at column 0: expected \'circle\'\n\n");
        return;
    }
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
