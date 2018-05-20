/* nest_loop2.c -- 嵌套循环打印图案 */
#include <stdio.h>

int main(void) 
{
    const int count = 6;
    int i, j;
    for(i = 0; i < count; i++) {
        for(j = 0; j <= i; j++) {
            printf("%c", 'F'-j);
        }
        printf("\n");
    }
    return 0;
}