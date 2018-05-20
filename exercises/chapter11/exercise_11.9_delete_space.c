/* delete_space.c -- 删除字符串中的空格 */
#include <stdio.h>
#include <string.h>
#define SIZE 3
void delete_space(char * str);

int main(void) 
{
    //const int SIZE = 3;
    char list[SIZE][16] = {
        "as tronomy", "asto unding", "astrop hys ics"
    };
    int i;
    
    for (i = 0; i < SIZE; i++) {
        delete_space(list[i]);
        puts(list[i]);
    }
    
    printf("\n---------------------------------------------\n");
    return 0;
}

void delete_space(char * str)
{
    char tmp[1024];
    char *ptr_src = str;
    char *ptr = tmp;
    while (*str) {
        if (*str != ' ') {
            *ptr++ = *str;
        }
        str++;
    }
    *(ptr) = '\0';
    
    strcpy(ptr_src, tmp);
}