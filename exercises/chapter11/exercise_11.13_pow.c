/* pow.c -- 计算幂 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) 
{
    double df = atof(argv[1]);
    int it = atoi(argv[2]);
    double result = 1.0;
    int i;
    
    for (i = 0; i < it; i++)
        result *= df;
    
    printf("%.2f^%d = %.2f\n", df, it, result);
    
    printf("\n---------------------------------------------\n");
    return 0;
}