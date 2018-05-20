/* int2ascii.c -- 将输入的int值输出为ASCII码 */
#include <stdio.h>

int main(void)
{
    int n;
    int n1;
    char c;
    printf("Please input two numbers:");
    scanf("%d %d", &n, &n1);
    c = n1;
    printf("You input %c and %c\n", n, c);
    
    //printf("Please input another number:");
    //scanf("%c", &c);
    //printf("You input %c\ %cn", c, &c);
    return 0;     
}