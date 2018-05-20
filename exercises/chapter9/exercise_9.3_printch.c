/* printch.c -- 按指定行列输出字符 */
#include <stdio.h>
void printch(char ch, int num, int row);
int main(void) 
{
    printch('a', 5, 6);
    printf("\n---------------------------------------------\n");
    return 0;
}

void printch(char ch, int num, int row)
{
    int i, j;
    for(i = 0; i < row; i++) {
        for (j = 0; j < num; j++)
            putchar(ch);
        putchar('\n');
    }
}