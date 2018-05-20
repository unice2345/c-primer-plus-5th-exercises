/* limits.c -- 计算极限 */
#include <stdio.h>

int main(void) 
{
    int count;
    int i;
    double sum = 0, sum2 = 0;
    printf("Enter count:");
    scanf("%d", &count);
    for(i = 1; i <= count; i++) {
        sum += 1.0/i;
        if (i % 2 == 0) {
            sum2 += 1.0/i;
        } else {
            sum2 -= 1.0/i;
        }
        
    }
    printf("sum is %f, sum2 is %f\n", sum, sum2);
    printf("\n---------------------------------------------\n");
    return 0;
}