/* arr_max.c -- 返回int数组中存储的最大值 */
#include <stdio.h>
int max_arr(int arr[], int n);
int main(void) 
{
    int src[5] = {1, 2, 3, 4, 5};
    printf("max value of array is %d", max_arr(src, 5));
    printf("\n---------------------------------------------\n");
    return 0;
}

int max_arr(int arr[], int n)
{
    int max = arr[0];
    int i;
    
    for (i = 1; i < n; i++) {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}