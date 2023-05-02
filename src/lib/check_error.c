#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int Check_Error(char* str)
{
    if (!(strncmp("circle", str, 6))) {
        if (!(isdigit(*(strchr(str, '(') + 1)))
            && !(*(strchr(str, '(') + 1) == '-')
            && !(*(strchr(str, '(') + 1) == '+')) {
            return 1;
        }
        if (!(isdigit(*(strchr(str, ' ') + 1)))
            && !(*(strchr(str, ' ') + 1) == '-')
            && !(*(strchr(str, ' ') + 1) == '+')) {
            return 2;
        }
        if (!(isdigit(*(strchr(str, ',') + 2)))
            && !(*(strchr(str, ',') + 1) == '+')) {
            return 3;
        }
        if (strtod(strchr(str, ',') + 1, NULL) <= 0) {
            return 4;
        } else
            return 0;
    } else
        return 5;
}
