/* sum_of_square.c -- 计算平方和 */
#include <stdio.h>

int main(void) 
{
    int min, max;
    int i;
    long sum;
    printf("Enter lower and upper integer limits:");
    scanf("%d%d", &min, &max);
    while (min < max) {
        sum = 0;
        for(i = min; i <= max; i++) {
            sum += i * i;
        }
        printf("The sums of the squares from %d to %d is %ld\n",
            min*min, max*max, sum);
        printf("Enter nex set of limits:");
        scanf("%d%d", &min, &max);
    }
    printf("Done\n");
    return 0;
}