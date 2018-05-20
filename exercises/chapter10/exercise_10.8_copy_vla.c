/* copy_vla.c -- 二维变长数组拷贝 */
#include <stdio.h>
void copy_arr(int src[], int dst[], int n);
void copy_ptr(int *src, int *dst, int n);
void show_arr(int arr[], int n);
void copy_arr2d(int rows, int cols, int src[rows][cols], int dst[rows][cols]);
void show_arr2d(int rows, int cols, int arr[rows][cols]);
int main(void) 
{
    int src[2][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 0}
    };
    int dst1[2][5];
    copy_arr2d(2, 5, src, dst1);
    show_arr2d(2, 5, dst1);
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

void copy_arr2d(int rows, int cols, int src[rows][cols], int dst[rows][cols])
{
    int i;
    
    for (i = 0; i < rows; i++)
        copy_arr(src[i], dst[i], cols);
}

void show_arr2d(int rows, int cols, int arr[rows][cols])
{
    int i;
    
    for (i = 0; i < rows; i++)
        show_arr(arr[i],  cols);
}