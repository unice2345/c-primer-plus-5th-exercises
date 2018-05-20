/* print_char.c -- 打印输入字符及其ASCII码 */
#include <stdio.h>

int main(void) 
{
    char ch;
    int char_count = 0;
    while ((ch = getchar()) != '#') {
        printf("%c %d; ", ch, ch);
        if (char_count++ % 8 == 0 && char_count >= 8)
            printf("\n");
    }
    
    printf("\n---------------------------------------------\n");
    return 0;
}