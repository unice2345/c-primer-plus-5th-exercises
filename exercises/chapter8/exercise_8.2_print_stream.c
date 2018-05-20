/* print_stream.c -- 打印字符流 */
#include <stdio.h>

int main(void) 
{
    char ch;
    int count = 0;
    
    while ((ch = getchar()) != EOF) {
        if (ch >= 32) { // 打印字符
            printf("%c %d; ", ch, ch);
        } else {        // 非打印字符
            if (ch == '\n')
                printf("\\n %d; ", ch);
            else if (ch == '\t')
                printf("\\t %d; ", ch);
            else    
                printf("^%c %d; ", ch + 64, ch);
        }
    }
    printf("count is %d\n", count);
    printf("\n---------------------------------------------\n");
    return 0;
}