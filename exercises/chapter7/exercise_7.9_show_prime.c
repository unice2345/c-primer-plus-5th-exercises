/* show_prime.c -- 打印素数 */
#include <stdio.h>
int is_prime(int n);
int main(void) 
{
    int number;
    int i;
    printf("Enter a number:");
    scanf("%d", &number);
    printf("Prime number are: ");
    for (i = 2; i <= number; i++) {
        if (is_prime(i))
            printf("%d ", i);
    }
    printf("\n---------------------------------------------\n");
    return 0;
}

int is_prime(int n)
{
    int i;
    
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}