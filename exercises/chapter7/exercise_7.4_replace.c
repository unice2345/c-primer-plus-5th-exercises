/* replace.c -- 替换输入字符 */
#include <stdio.h>

int main(void) 
{
    char ch;
    int count = 0;
    
    while ((ch = getchar()) != '#') {
        if (ch == '.') {
            putchar('!');
            count++;
        }
        else
            putchar(ch);
            
        if (ch == '!') {
            putchar('!');
            count++;
        }
    }
    printf("replace %d times.", count);
    
    printf("\n---------------------------------------------\n");
    return 0;
}