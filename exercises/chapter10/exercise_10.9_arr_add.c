/* arr_add.c -- 数组相加 */
#include <stdio.h>
void copy_arr(int src[], int dst[], int n);
void copy_ptr(int *src, int *dst, int n);
void show_arr(int arr[], int n);
void arr_add(int src0[], int src1[], int dst[], int n);
int main(void) 
{
    int src0[4] = {2, 4, 5, 8};
    int src1[4] = {1, 0, 4, 6};
    int dst[4];
    
    arr_add(src0, src1, dst, 4);
    show_arr(dst, 4);
    printf("\n---------------------------------------------\n");
    return 0;
}

void copy_arr(int src[], int dst[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        dst[i] = src[i];
}

void copy_ptr(int *src, int *dst, int n)
{
    int *end = src + n;
    while (src < end)
        *dst++ = *src++;
}

void show_arr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}

void arr_add(int src0[], int src1[], int dst[], int n)
{
    int i;
    
    for (i = 0; i < n; i++)
        dst[i] = src0[i] + src1[i];
}