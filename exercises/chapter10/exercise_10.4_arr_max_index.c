/* arr_max_index.c -- 返回int数组中存储的最大值的索引 */
#include <stdio.h>
int max_arr_index(double arr[], int n);
int main(void) 
{
    double src[5] = {1, 2, 3, 4, 5};
    printf("max value index of array is %d", max_arr_index(src, 5));
    printf("\n---------------------------------------------\n");
    return 0;
}

int max_arr_index(double arr[], int n)
{
    int max = arr[0];
    int i;
    int max_index = 0;
    
    for (i = 1; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
            max_index = i;
        }
    }
    return max_index;
}