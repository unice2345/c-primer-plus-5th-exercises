/* print_table.c -- 打印表格 */
#include <stdio.h>

int main(void) 
{
    int min, max;
    int i;
    printf("Enter min and max value:");
    scanf("%d%d", &min, &max);
    for(i = min; i <= max; i++) {
        printf("%5d %5d %5d\n", i, i*i, i*i*i);
    }
    return 0;
}