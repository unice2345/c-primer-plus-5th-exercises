/* min2hour.c -- 分钟转换为小时和分钟 */
#include <stdio.h>

int main(void)
{
    const int MIN_PER_HOUR = 60;
    int min;
    int hour, left_min;
    
    min = 1;
    while( min > 0) {
        printf("Input mins: ");
        scanf("%d", &min);
        hour = min / MIN_PER_HOUR;
        left_min = min % MIN_PER_HOUR;
        printf("%d hours and %d mins.\n", hour, left_min);
    }
    
    return 0;
}