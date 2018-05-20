/* print_int2.c -- 打印输入的整数信息 */
#include <stdio.h>

int main(void) 
{
    int even_count = 0, odd_count = 0;
    float even_sum = 0, odd_sum = 0;
    int x;
    while (scanf("%d", &x) && x != 0) {
        switch (x % 2) 
        {
        case 0:
            even_count ++;
            even_sum += x;
            break;
        case 1:
            odd_count ++;
            odd_sum += x;
            break;
        }
    }
        
    printf("even_count is %d, even_aver is %.2f\n", even_count, even_count > 0 ? even_sum / even_count : 0);
    printf("odd_count is %d, odd_aver is %.2f\n", odd_count, odd_count > 0 ? odd_sum / odd_count : 0);
    printf("\n---------------------------------------------\n");
    return 0;
}