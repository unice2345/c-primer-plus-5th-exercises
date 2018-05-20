/* pe15-1.c -- 程序的功能 */
#include <stdio.h>

int str2value(const char *str);
int main(void) 
{
    char * pbin = "01001001";
    printf("%d\n", str2value(pbin));
    printf("\n---------------------------------------------\n");
    return 0;
}

int str2value(const char *str)
{
    int value = 0;
    
    while (*str != '\0') {
        value += *str - '0';
        //printf("str = %c, value = %d \n", *str, value);
        value <<= 1;
        
        str++;
    }
    value >>= 1;
    
    return value;
}