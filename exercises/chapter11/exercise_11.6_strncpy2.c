/* strncpy2.c -- 实现strncpy  */
#include <stdio.h>

char* strncpy2(char* s1, char *s2, int n);

int main(void) 
{
 
    char s1[64] = "THIS IS A STRING.";
    char * strs[2] = {
         "Alloha!",
        "hell"
    };
    char *ptr;
    int i;
    
    for (i = 0; i < 2; i++) {
        ptr = strncpy2(s1, strs[i], 5);
        puts(ptr);
    }
    
    printf("\n---------------------------------------------\n");
    return 0;
}

char* strncpy2(char* s1, char *s2, int n)
{
    int i = 0;
    char * ptr = s1;
    while (*s2 && i < n) {
        *s1++ = *s2++;
        i++;
    }
    
    if (i < n)
        *s1 = '\0';
    return ptr;
    
}