/* print_array.c -- 打印数组 */
#include <stdio.h>

int main(void) 
{
    char chs[26];
    int i;
    for(i = 0; i < 26; i++) {
        chs[i] = 'a' + i;
    }
    for(i = 0; i < 26; i++) {
        printf("%c", chs[i]);
    }
    printf("\n");
    return 0;
}