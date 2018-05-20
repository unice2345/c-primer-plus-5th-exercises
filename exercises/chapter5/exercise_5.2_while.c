/* while.c -- 使用while */
#include <stdio.h>

int main(void)
{
    int n, m;
    printf("Input a int:");
    scanf("%d", &n);
    m = n + 10;
    while(n <= m) {
        printf("%d ", n++);
    }
    return 0;
}