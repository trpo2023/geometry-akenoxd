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

int main()
{
    double n;
    char str[100];
    FILE* data;
    data = fopen("example", "r");
    if (data == NULL) {
        printf("Error opening file");
        return 1;
    }
    while (fgets(str, 100, data) != NULL) {
        n = strtod(strchr(str, '(') + 1, NULL);
        printf("%.2f \n", n);
        puts(str);
    }
    return 0;
}
