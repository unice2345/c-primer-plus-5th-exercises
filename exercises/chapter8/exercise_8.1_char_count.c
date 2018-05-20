/* char.c -- 统计字符个数 */
#include <stdio.h>

int main(void) 
{
    char ch;
    int count = 0;
    
    while ((ch = getchar()) != EOF) {
        count++;
        putchar(ch);
    }
    printf("count is %d\n", count);
    printf("\n---------------------------------------------\n");
    return 0;
}