/* pe16-2.c -- 调和平均值 */
#include <stdio.h>
#define HARMONIC_MEAN(X, Y) ((2.0 * (X) * (Y)) / ((X) + (Y)))
#define PR(X, Y) printf("Harmonic mean of " #X " and " #Y " is %.2f\n", HARMONIC_MEAN(X, Y))
int main(void) 
{
    PR(1, 2);
    PR(2, 2);
    printf("\n---------------------------------------------\n");
    return 0;
}