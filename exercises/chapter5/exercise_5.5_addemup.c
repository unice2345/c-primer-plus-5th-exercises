/* addemup.c -- 计算和 */
#include <stdio.h>

int main(void)
{
    int count, sum;
    int max_count;
    printf("Enter max count:");
    scanf("%d", &max_count);
    count = 0;
    sum = 0;
    
    while(count ++ < max_count) {
        //sum += count;
        sum += count*count;
    }
    printf("sum = %d\n", sum);
    return 0;
}