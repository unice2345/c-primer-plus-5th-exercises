/* chline.c -- 在特定列输出字符 */
#include <stdio.h>
void chline(char ch, int i, int j);
int main(void) 
{
    chline('c', 5, 10);
    printf("\n---------------------------------------------\n");
    return 0;
}

/* 在第i到j列输出字符ch */
void chline(char ch, int i, int j)
{
    int col;
    
    for(col = 1; col <= j; col++) {
        if (col < i)
            putchar(' ');
        else
            putchar(ch);
    }
    putchar('\n');
}