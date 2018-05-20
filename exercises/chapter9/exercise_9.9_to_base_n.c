/* to_base_n.c -- 以N进制形式输出整数 */
#include <stdio.h>
void to_binary(unsigned long n);
void to_base_n(unsigned long number, int base);
int main(void) 
{
    unsigned long number;
    printf("Enter an integer (q to quit):\n");
    while (scanf("%lu", &number) == 1) {
        printf("Binary equivalent: ");
        to_binary(number);
        putchar('\n');
        printf("Octonary equivalent: ");
        to_base_n(number, 8);
        putchar('\n');
        printf("Hex equivalent: ");
        to_base_n(number, 16);
        putchar('\n');
        printf("Enter an integer (q to quit):\n");
    }
    printf("Done.\n");
    printf("\n---------------------------------------------\n");
    return 0;
}

void to_binary(unsigned long n)
{
    int r;
    r = n % 2;
    if (n >= 2) {
        to_binary(n / 2);
    }
    putchar('0' + r);
}

void to_base_n(unsigned long number, int base) 
{
    int r;
    r = number % base;
    if (number >= base) {
        to_base_n(number / base, base);
    }
    
    if (r < 10)
        printf("%d", r);
    else
        putchar('a' + r - 10);
}