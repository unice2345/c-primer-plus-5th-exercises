/* swap3.c -- 使用指针完成交换 */
#include <stdio.h>
void interchange(int * u, int * v);
int main(void) 
{
    int x = 5, y = 10;
    printf("Originally x = %d, y = %d\n", x, y);
    interchange(&x, &y);  /* 向函数传入变量的地址 */
    printf("Now x = %d, y = %d\n", x, y);
    printf("\n---------------------------------------------\n");
    return 0;
}

void interchange(int * u, int * v)
{
    int temp;
    
    temp = *u;
    *u = *v;
    *v = temp;
}