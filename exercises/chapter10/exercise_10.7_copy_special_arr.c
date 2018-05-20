/* copy_special_arr.c -- 数组拷贝 */
#include <stdio.h>
void copy_arr(int src[], int dst[], int n);
void copy_ptr(int *src, int *dst, int n);
void show_arr(int arr[], int n);
int main(void) 
{
    int src[7] = {1, 2, 3, 4, 5, 6, 7};
    int dst1[3];
    copy_arr(src + 2, dst1, 3);
    show_arr(dst1, 3);
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