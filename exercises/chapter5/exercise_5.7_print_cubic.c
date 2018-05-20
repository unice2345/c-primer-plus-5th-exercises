/* print_cubic.c -- 计算立方值并打印 */
#include <stdio.h>

void print_cubic(float x)
{
    printf("cubic is %f\n", x*x*x);
}

int main(void)
{
    float x;
    printf("Enter a value: ");
    scanf("%f", &x);
    print_cubic(x);
    return 0;
}