#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Check_Error(char* str)
{
    if (!(strncmp("circle", str, 6))) {
        if (!(isdigit(*(strchr(str, '(') + 1)))
            && !(*(strchr(str, '(') + 1) == '-')
            && !(*(strchr(str, '(') + 1) == '+')) {
            printf("%s", str);
            for (int i = 0; i < strchr(str, '(') - &str[0] + 1; i++)
                printf(" ");
            printf("^\n");
            printf("Error at column %ld: expected \'double\'\n\n",
                   strchr(str, '(') - &str[0] + 1);
            return 0;
        }
        if (!(isdigit(*(strchr(str, ' ') + 1)))
            && !(*(strchr(str, ' ') + 1) == '-')
            && !(*(strchr(str, ' ') + 1) == '+')) {
            printf("%s", str);
            for (int i = 0; i < (strchr(str, ' ') - &str[0] + 1); i++)
                printf(" ");
            printf("^\n");
            printf("Error at column %ld: expected \'double\'\n\n",
                   strchr(str, ' ') - &str[0] + 1);
            return 0;
        }
        if (!(isdigit(*(strchr(str, ',') + 2)))
            && !(*(strchr(str, ',') + 1) == '+')) {
            printf("%s", str);
            for (int i = 0; i < (strchr(str, ',') - &str[0] + 2); i++)
                printf(" ");
            printf("^\n");
            printf("Error at column %ld: expected \'double\'\n\n",
                   strchr(str, ',') - &str[0] + 1);
            return 0;
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
    } else {
        printf("%s \n^\n", str);
        printf("Eror at column 0: expected \'circle\'\n\n");
        return 0;
    }
}
