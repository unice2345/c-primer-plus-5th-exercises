/* reverse_input.c -- 翻转输入的内容 */
#include <stdio.h>

int main(void) 
{
    char chs[255];
    int i = 0;
    
    while (scanf("%c", &chs[i]) && chs[i] != '\n')
        i++;
    
    while (i >= 0)
        putchar(chs[i--]);
    printf("\n---------------------------------------------\n");
    return 0;
}