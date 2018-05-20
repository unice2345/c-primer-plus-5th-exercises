/* pe15-3.c -- 程序的功能 */
#include <stdio.h>
#include <stdlib.h>

char * itobs(int , char *);
void show_bstr(const char * str);
int str2value(const char *str);

int get_open_num(int x);

int main(int argc, char * argv[]) 
{
    char bin_str[8 * sizeof(int) + 1];
    unsigned int value1, value2;
    
    value1 = 0x10f1;
    show_bstr(itobs(value1, bin_str));
    printf("Open count is %d\n", get_open_num(value1));
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

int get_open_num(int x)
{
    int count = 0;
    
    while(x > 0) {
        if (x & 0x1)
            count++;
        x >>= 1;
    }
    return count;
}