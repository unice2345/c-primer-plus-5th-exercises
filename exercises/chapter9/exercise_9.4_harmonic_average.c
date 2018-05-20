/* harmonic_aver.c -- 计算谐均值 */
#include <stdio.h>
double harmonic_aver(double x, double y);
int main(void) 
{
    double x = 2, y = 4;
    printf("Harmonic aver of %.2f and %.2f is %.2f.\n", x, y, harmonic_aver(x, y));
    printf("\n---------------------------------------------\n");
    return 0;
}

double harmonic_aver(double x, double y)
{
    return 2.0 / (1.0/x + 1.0/y);
}