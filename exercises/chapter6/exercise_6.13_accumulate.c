/* accumulate.c -- 计算数组的累积和 */
#include <stdio.h>

int main(void) 
{
    const int SIZE = 8;
    double a[SIZE], accum[SIZE];
    int i;
    printf("Enter %d values:", SIZE);
    for(i = 0; i < SIZE; i++) {
        scanf("%lf", &a[i]);
        if (i > 0) {
            accum[i] = accum[i-1] + a[i];
        } else {
            accum[i] = a[i];
        }
    }
    
    for(i = 0; i < SIZE; i++) {
        printf("%5.2f ", a[i]);
    }
    printf("\n");
    for(i = 0; i < SIZE; i++) {
        printf("%5.2f ", accum[i]);
    }
    printf("\n---------------------------------------------\n");
    return 0;
}