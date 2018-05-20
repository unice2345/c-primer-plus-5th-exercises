/* 13.4_parrot.c -- 回显 */
#include <stdio.h>
#define MAXLINE 20

int main(void)
{
    char line[MAXLINE];
    
    while (fgets(line, MAXLINE, stdin) != NULL && line[0] != '\n')
        fputs(line, stdout);
    
    return 0;
}