/* min.c --  获得较小值 */
#include <stdio.h>
double min(double x, double y);
int main(void) 
{
    double x = 1.0, y = 2.0;
    printf("Min of %.2f and %.2f is %.2f\n", x, y, min(x, y));
    printf("\n---------------------------------------------\n");
    return 0;
}

double min(double x, double y)
{
    return (x < y) ? x : y;
}