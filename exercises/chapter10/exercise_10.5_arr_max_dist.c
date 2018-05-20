/* arr_max_dist.c -- 返回数组中最大值和最小值的差值 */
#include <stdio.h>
int max_arr_dist(double arr[], int n);
int main(void) 
{
    double src[5] = {1, 2, 3, 4, 5};
    printf("dist of array is %d", max_arr_dist(src, 5));
    printf("\n---------------------------------------------\n");
    return 0;
}

int max_arr_dist(double arr[], int n)
{
    int max = arr[0];
    int min = arr[0];
    int i;
    
    for (i = 1; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    return max - min;
}