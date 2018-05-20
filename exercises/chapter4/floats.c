/* floats.c -- 一些浮点数的组合 */
#include <stdio.h>

int main(void)
{
    const double RENT = 3852.99;
    
    printf("*%f*\n", RENT);
    printf("*%e*\n", RENT);
    printf("*%4.2f*\n", RENT);
    printf("*%3.1f*\n", RENT);
    printf("*%10.3f*\n", RENT);
    printf("*%12.5e*\n", RENT);
    return 0;
}