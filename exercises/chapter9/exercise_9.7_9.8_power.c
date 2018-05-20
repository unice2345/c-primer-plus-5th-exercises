/* power.c -- 求幂运算 */
#include <stdio.h>
#include <math.h>
double power(double n, int p);
double power2(double n, int p);
int main(void) 
{
    printf("power(%.2f, %d) is %.2f.\n", 2.0, 3, power(2, 3));
    printf("power(%.2f, %d) is %f.\n", 2.0, -3, power(2, -3));
    printf("power(%.2f, %d) is %.2f.\n", 0.0, -3, power(0, -3));
    printf("power(%.2f, %d) is %.2f.\n", 2.0, 0, power(2, 0));
    
    printf("power2(%.2f, %d) is %.2f.\n", 2.0, 3, power2(2, 3));
    printf("power2(%.2f, %d) is %f.\n", 2.0, -3, power2(2, -3));
    printf("power2(%.2f, %d) is %.2f.\n", 0.0, -3, power2(0, -3));
    printf("power2(%.2f, %d) is %.2f.\n", 2.0, 0, power2(2, 0));
    printf("\n---------------------------------------------\n");
    return 0;
}

double power(double n, int p)
{
    if (fabs(n) <= 0.000001) 
        return 0;
    if (p == 0)
        return 1;
        
    double pow = 1;
    int count, i;
    count = (p > 0) ? p : -p;
    for (i = 1; i <= count; i++) {
        pow *= n;
    }
    
    return (p > 0) ? pow : 1.0/pow;
}

/* 以递归方式实现 */
double power2(double n, int p)
{
    if (fabs(n) <= 0.000001) 
        return 0;
    if (p == 0)
        return 1;
    if (p < 0)
        return 1.0 / power2(n, -p);
        
    return n * power2(n, p-1);
}