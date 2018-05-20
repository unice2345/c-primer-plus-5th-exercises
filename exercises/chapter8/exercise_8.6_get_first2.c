/* get_first2.c -- 获取第一个非空字符 */
#include <stdio.h>
char get_first(void);
int main(void) 
{
    char ch = get_first();
    printf("You entered %c.\n", ch);
    printf("\n---------------------------------------------\n");
    return 0;
}

char get_first(void)
{
    char ch;
    ch = getchar();
    while (ch  == ' ' || ch == '\t' || ch == '\n') {
        ch = getchar();
    }
    return ch;
}