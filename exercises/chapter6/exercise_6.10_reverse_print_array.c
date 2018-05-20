/* reverse_print_array.c -- 逆序打印int数组 */
#include <stdio.h>

int main(void) 
{
    const int SIZE = 8;
    int a[SIZE];
    int i;
    printf("Enter %d integer numbers:", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &a[i]);
    }
    for (i = SIZE-1; i >= 0; i--) {
        printf("%d ", a[i]);
    }
        
    printf("\n---------------------------------------------\n");
    return 0;
}