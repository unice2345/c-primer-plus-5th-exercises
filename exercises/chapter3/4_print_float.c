/* print_float.c -- 按指定格式打印浮点数 */
#include <stdio.h>

int main(void)
{
    float f;
    printf("Please input a float number:");
    scanf("%f", &f);
    printf("%f, %e\n", f, f);
    return 0;    
}