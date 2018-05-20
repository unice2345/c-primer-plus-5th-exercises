/* echo.c -- 回显 */
#include <stdio.h>

int main(void) 
{
    char ch;
    while ((ch = getchar()) != '#')
        putchar(ch);
    printf("\n---------------------------------------------\n");
    return 0;
}