/* pe12-8.c -- 产生数组 */
#include <stdio.h>
#include <stdlib.h>

int *make_array(int elem, int val);
void show_array(const int ar[], int n);
int main(void) 
{
    int *pa;
    int size;
    int value;
    
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    while (size > 0) {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa) {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements(<1 to quit): ");
        scanf("%d", &size);
    }
    printf("\n---------------------------------------------\n");
    return 0;
}

int *make_array(int elem, int val)
{
    int *p;
    int i;
    
    p = (int*) malloc(elem * sizeof(int));
    
    for (i = 0; i < elem; i++)
        p[i] = val;
    
    return p;
}

void show_array(const int ar[], int n)
{
    int i;
    
    for (i = 0; i < n; i++) {
        if (i % 8 == 0) putchar('\n');
        printf("%d ", ar[i]);
    }
}