/* search_substr.c -- 搜索子字符串 */
#include <stdio.h>
#include <string.h>

const char* search_substr(const char *target, const char *str);

int main(void) 
{
    const int SIZE = 3;
     char * list[3] = {
        "astronomy", "astounding", "astrophysics"
    };
    int i;
    const char * ptr;
    
    for (i = 0; i < SIZE; i++) {
        ptr = search_substr("stron", list[i]);
        if (ptr)
            puts(ptr);
        else
            puts("Not found.");
    }
    
    printf("\n---------------------------------------------\n");
    return 0;
}

const char* search_substr(const char *target, const char *str)
{
    const char* ptr;
    
    ptr = str;
    while (*ptr) {
        if (strncmp(target, ptr, strlen(target)) == 0)
            return ptr;
        ptr++;
    }
    
    return NULL;
}