/* fibonacci.c -- Fibonacci数列 */
#include <stdio.h>
long fibonacci(int n);
int main(void) 
{
    int i;
    for (i = 1; i <= 7; i++)
        printf("%ld ", fibonacci(i));
    printf("\n---------------------------------------------\n");
    return 0;
}

long fibonacci(int n)
{
    int sum = 1, prev_sum = 1, new_sum;
    int i;
    
    for (i = 3; i <= n; i++) {
        new_sum = sum + prev_sum;
        prev_sum = sum;
        sum = new_sum;
    }
    return sum;
}