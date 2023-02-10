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
/* void AddCirlce(struct circle* circle, int n)
{
    circle = (struct circle*)realloc(struct circle, sizeof());
}
 */
int main()
{
    int i = 1;
    int n;
    char str[100];
    FILE* data;
    data = fopen("example", "r");
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
        puts(str);
        i++;
    }
    for (int i = 0; i < n; i++) {
        printf("%.2lf %.2lf, %.2lf \n",
               circle[i].point.x,
               circle[i].point.y,
               circle[i].r);
    }
    return 0;
    free(circle);
}