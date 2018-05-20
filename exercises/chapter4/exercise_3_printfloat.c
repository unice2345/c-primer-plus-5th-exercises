/* printfloat.c -- 按指定的格式打印输入的浮点数 */
#include <stdio.h>

int main(void)
{
    float f;
    printf("Input a float number:");
    scanf("%f", &f);
    printf("The input is %f or %e\n", f, f);
}