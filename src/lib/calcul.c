#define _USE_MATH_DEFINES
#include <math.h>

int Intersect(int x1, int y1, int x2, int y2, double r1, double r2)
{
    double SR, D;
    SR = r1 + r2;
    D = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    if (SR >= D)
        return 1;
    else
        return 0;
}

float Circle_Area(double radius)
{
    return M_PI * radius * radius;
}
float Circle_Perimeter(double radius)
{
    return 2 * M_PI * radius;
}
