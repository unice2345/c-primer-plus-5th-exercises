/* copy_arr.c -- 数组拷贝 */
#include <stdio.h>
void copy_arr(int src[], int dst[], int n);
void copy_ptr(int *src, int *dst, int n);
void show_arr(int arr[], int n);
int main(void) 
{
    int src[5] = {1, 2, 3, 4, 5};
    int dst1[5], dst2[5];
    copy_arr(src, dst1, 5);
    copy_ptr(src, dst2, 5);
    show_arr(dst1, 5);
    show_arr(dst2, 5);
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