#include <stdio.h>

struct point {
    double x;
    double y;
};

struct circle {
    struct point point;
    double r;
};

int main()
{
    struct circle circle[10];
    int n = 0;

    scanf("%d", &n);

    for (int i = 0; i < 3; i++) {
        scanf("circle(%lf %lf, %lf)\n",
              &circle[i].point.x,
              &circle[i].point.y,
              &circle[i].r);
    }

    return 0;
}