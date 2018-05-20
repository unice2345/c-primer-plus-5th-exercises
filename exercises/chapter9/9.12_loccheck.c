/* loccheck.c -- 查看变量的存储地址 */
#include <stdio.h>
void loccheck(int);    /* 函数声明 */
int main(void) 
{
    int x = 2;
    int y = x;
    
    printf("In main(), x = %d, &x = %p\n", x, &x);
    printf("In main(), y = %d, &y = %p\n", y, &y);
    loccheck(x);
    
    printf("\n---------------------------------------------\n");
    return 0;
}

void loccheck(int x)
{
    int y = x;
    
    printf("In loccheck(), x = %d, &x = %p\n", x, &x);
    printf("In loccheck(), y = %d, &y = %p\n", y, &y);
}