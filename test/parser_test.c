#include "ctest.h"
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include <calcul.h>
#include <check_error.h>
#include <print.h>

CTEST(checkInputOk, t1)
{
    char* str = "circle(1.0 1.0, 2)";
    const int expected = 0;
    const int real = Check_Error(str);
    ASSERT_EQUAL(expected, real);
}

CTEST(checka, t1)
{
    char* str = "circle(as 1.0, 2)";
    const int expected = 1;
    const int real = Check_Error(str);
    ASSERT_EQUAL(expected, real);
}

CTEST(checkb, t1)
{
    char* str = "circle(1 B, 2)";
    const int expected = 2;
    const int real = Check_Error(str);
    ASSERT_EQUAL(expected, real);
}

CTEST(checkc, t1)
{
    char* str = "circle(1 4, L)";
    const int expected = 3;
    const int real = Check_Error(str);
    ASSERT_EQUAL(expected, real);
}

CTEST(checkd, t1)
{
    char* str = "circle(1 4, 0)";
    const int expected = 4;
    const int real = Check_Error(str);
    ASSERT_EQUAL(expected, real);
}

CTEST(checkf, t1)
{
    char* str = "circl(1.0 1.0, 2)";
    const int expected = 5;
    const int real = Check_Error(str);
    ASSERT_EQUAL(expected, real);
}