/* is_within.c -- 判断字符是否在字符串中  */
#include <stdio.h>

int is_within(char c, const char* str);

int main(void) 
{
 
    char c = 'a';
    const char * strs[2] = {
        "hello",
        "Alloha!"
    };
    int i;
    
    for (i = 0; i < 2; i++) {
        printf("%c is ", c);
        if (is_within(c, strs[i])) {
            printf("in ");
        } else {
            printf("not in ");
        }
        printf("%s\n", strs[i]);
    }
    
    printf("\n---------------------------------------------\n");
    return 0;
}

int is_within(char c, const char* str)
{
    while (*str) {
        if (c == *str++)
            return 1;
    }
    return 0;
}