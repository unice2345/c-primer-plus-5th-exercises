/* print_array.c -- 打印int数组 */
#include <stdio.h>

int main(void) 
{
    const int SIZE = 8;
    int a[SIZE];
    int i;
    int sum = 1;
    for (i = 0; i < SIZE; i++) {
        a[i] = sum;
        //printf("%d ", a[i]);
        sum *= 2;
    }
    i = SIZE - 1;
    do {
        printf("%d ", a[i]);
    } while(i-- > 0);
        
    printf("\n---------------------------------------------\n");
    return 0;
}