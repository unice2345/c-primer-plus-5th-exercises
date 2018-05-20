/* defines.c -- 使用limist.h和float.h中定义的常量 */
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("Biggest int: %d\n", INT_MAX);
    printf("Smallest unsigned long: %lld\n", LLONG_MIN);
    printf("One byte = %d bits on this system.\n", CHAR_BIT);
    printf("Largest double: %e\n", DBL_MAX);
    printf("Smallest float: %e\n", FLT_MIN);
    printf("float precision = %d\n", FLT_DIG);
    printf("float epsilon = %e\n", FLT_EPSILON);
    return 0;
}
