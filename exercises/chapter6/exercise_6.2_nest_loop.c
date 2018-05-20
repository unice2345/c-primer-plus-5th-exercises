/* nest_loop.c -- 嵌套循环 */
#include <stdio.h>

int main(void) 
{
    const int count = 5;
    int i, j;
    for(i = 0; i < count; i++) {
        for(j = 0; j <= i; j++) {
            printf("$");
        }
        printf("\n");
    }
    return 0;
}