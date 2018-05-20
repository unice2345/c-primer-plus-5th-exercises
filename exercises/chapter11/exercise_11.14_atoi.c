/* atoi.c -- 实现atoi */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int atoi(const char* str);

int main(int argc, char* argv[]) 
{
    printf("You input %d.\n", atoi(argv[1]));
    
    printf("\n---------------------------------------------\n");
    return 0;
}

int atoi(const char* str)
{
    int result;
    
    result = 0;
    while (*str != '\0') {
        if (isdigit(*str)) {
            result = result * 10 + (*str - '0');
            str++;
        } else 
            break;
    }
    
    return result;
}