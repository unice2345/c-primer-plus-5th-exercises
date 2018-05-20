/* count.c -- 程序调用次数 */
#include <stdio.h>

int count() {
    static int count = 0;
    return ++count;
}

int main(void) 
{
    int i;
    for (i = 0; i < 10; i++) {
        printf("count() called %d times.\n", count());
    }
    printf("\n---------------------------------------------\n");
    return 0;
}