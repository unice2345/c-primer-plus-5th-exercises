/* reverse_string.c -- 字符串翻转 */
#include <stdio.h>
#include <string.h>
#define SIZE 3
void reverse_string(char * str);

int main(void) 
{
    //const int SIZE = 3;
    char list[SIZE][16] = {
        "astronomy", "astounding", "astrophysics"
    };
    int i;
    
    for (i = 0; i < SIZE; i++) {
        reverse_string(list[i]);
        puts(list[i]);
    }
    
    printf("\n---------------------------------------------\n");
    return 0;
}

void reverse_string(char * str)
{
    int len = strlen(str);
    int i;
    char c;
    
    for (i = 0; i < len/2; i++) {
        c = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = c;
    }
}