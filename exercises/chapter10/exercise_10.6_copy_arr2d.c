/* copy_arr2d.c -- 二维数组拷贝 */
#include <stdio.h>
void copy_arr(int src[], int dst[], int n);
void copy_ptr(int *src, int *dst, int n);
void copy_arr2d(int src[][5], int dst[][5], int n);
void show_arr(int arr[], int n);
void show_arr2d(int arr[][5], int n);
int main(void) 
{
    int src[2][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 0}
    };
    int dst1[2][5];
    copy_arr2d(src, dst1, 2);
    show_arr2d(dst1, 2);
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