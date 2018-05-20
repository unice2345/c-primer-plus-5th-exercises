/* pe15-5.c -- 程序的功能 */
#include <stdio.h>
#include <stdlib.h>

char * itobs(int , char *);
void show_bstr(const char * str);

unsigned int rotate_l(unsigned int x, int num);

int main(int argc, char * argv[]) 
{
    char bin_str[8 * sizeof(int) + 1];
    unsigned int value1, rotate_value;
    int num = 4;
    
    value1 = 0xf00010f1;
    rotate_value = rotate_l(value1, num);
    puts("value1:");
    show_bstr(itobs(value1, bin_str));
    printf("rotate %d bits\n", num);
    puts("rotate value1:");
    show_bstr(itobs(rotate_value, bin_str));
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

unsigned int rotate_l(unsigned int x, int num)
{
    unsigned int mask = 0x80000000;
    unsigned int left = 0;
    int i;
    
    for (i = 0; i < num; i++) {
        left = (left << 1) + ((x & mask) == mask);
//        printf("x & mask = %d\n", ((x & mask) == mask));
//        printf("left is %d\n", left);
        x <<= 1;
    }
    return x | left;
}