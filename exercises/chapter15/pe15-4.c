/* pe15-4.c -- 程序的功能 */
#include <stdio.h>
#include <stdlib.h>

char * itobs(int , char *);
void show_bstr(const char * str);

int is_bit_open(int x, int pos);

int main(int argc, char * argv[]) 
{
    char bin_str[8 * sizeof(int) + 1];
    unsigned int value1;
    int pos = 4;
    
    value1 = 0x10f1;
    show_bstr(itobs(value1, bin_str));
    printf("Is bit %d of %d open ? %d\n", pos, value1, is_bit_open(value1, pos));
    return 0;
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

int is_bit_open(int x, int pos)
{
    return (x >> pos) & 0x1;
}