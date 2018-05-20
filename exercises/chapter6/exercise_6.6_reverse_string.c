/* reverse_string.c -- 逆序打印输入的字符串 */
#include <stdio.h>
#include <string.h>
int main(void) 
{
    char str[64];
    int i;
    printf("Enter string:");
    scanf("%s", str);
    for(i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}