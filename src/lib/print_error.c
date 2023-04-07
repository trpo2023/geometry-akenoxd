#include <stdio.h>
#include <string.h>

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
        printf("%s \n^\n", str);
        printf("Eror at column 0: expected \'circle\'\n\n");
        return;
    }
};
