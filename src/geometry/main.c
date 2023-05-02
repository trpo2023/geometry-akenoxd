#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <calcul.h>
#include <check_error.h>
#include <print.h>

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
        if (str[0] == '\0')
            break;
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
    Print_Result(circle, nCircle);
    free(circle);
    return 0;
}