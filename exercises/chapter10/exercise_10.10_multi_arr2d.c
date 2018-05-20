/* multi_arr2d.c -- 二维数组翻倍 */
#include <stdio.h>
void copy_arr(int src[], int dst[], int n);
void copy_ptr(int *src, int *dst, int n);
void copy_arr2d(int src[][5], int dst[][5], int n);
void multi_arr2d(int src[][5], int dst[][5], int n, int scale);
void show_arr(int arr[], int n);
void show_arr2d(int arr[][5], int n);
int main(void) 
{
    int src[3][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 0},
        {11, 12, 13, 14, 15}
    };
    int dst1[3][5];
    multi_arr2d(src, dst1, 3, 2);
    show_arr2d(dst1, 3);
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

void copy_arr2d(int src[][5], int dst[][5], int n)
{
    int i;
    
    for (i = 0; i < n; i++)
        copy_arr(src[i], dst[i], 5);
}

void show_arr2d(int arr[][5], int n)
{
    int i;
    
    for (i = 0; i < n; i++)
        show_arr(arr[i], 5);
}

void multi_arr2d(int src[][5], int dst[][5], int n, int scale)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < 5; j++)
            dst[i][j] = src[i][j] * scale;
}