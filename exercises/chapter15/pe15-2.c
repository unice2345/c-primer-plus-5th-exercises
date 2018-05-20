/* pe15-2.c -- 程序的功能 */
#include <stdio.h>
#include <stdlib.h>

char * itobs(int , char *);
void show_bstr(const char * str);
int str2value(const char *str);
int main(int argc, char * argv[]) 
{
    char bin_str[8 * sizeof(int) + 1];
    unsigned int value1, value2;
    
    if (argc < 3) {
        fprintf(stderr, "Usage: %s binary_str0 binary_str1", argv[0]);
        exit(1);
    }
    
    value1 = str2value(argv[1]);
    value2 = str2value(argv[2]);
    puts("Value1:");
    show_bstr(itobs(value1, bin_str));
    puts("Value2:");
    show_bstr(itobs(value2, bin_str));
    puts("~Value1:");
    show_bstr(itobs(~value1, bin_str));
    puts("~Value2:");
    show_bstr(itobs(~value2, bin_str));
    puts("Value1 & Value2:");
    show_bstr(itobs(value1 & value2, bin_str));
    puts("Value1 | Value2:");
    show_bstr(itobs(value1 | value2, bin_str));
    puts("Value1 ^ Value2:");
    show_bstr(itobs(value1 ^ value2, bin_str));
    
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

char * itobs(int n, char * ps)
{
    int i;
    static int size = 8 * sizeof(int);
    
    for (i = size-1; i >= 0; i--, n >>= 1) {
        ps[i] = (n & 0x1) + '0';
    }
    ps[size] = '\0';
    
    return ps;
}

void show_bstr(const char * str)
{
    int i = 0;
    
    while (str[i]) {
        putchar(str[i]);
        if (++i % 4 == 0 && str[i])
            putchar(' ');
    }
    putchar('\n');
}