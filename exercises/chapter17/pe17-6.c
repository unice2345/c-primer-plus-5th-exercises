/* pe17-6.c -- 折半查找 */
#include <stdio.h>

int find(int arr[], int num, int value);
int search(int arr[], int begin, int end, int value);
int main(void) 
{
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int value = 12;
    
    if (find(array, 10, value)) {
        printf("%d is found\n", value);
    } else {
        printf("%d is not found\n", value);
    }
    
    printf("\n---------------------------------------------\n");
    return 0;
}

int find(int arr[], int num, int value)
{
    return search(arr, 0, num-1, value);
}

int search(int arr[], int begin, int end, int value) {
    
    int i;
    
    if (end == begin) {
        if (arr[begin] == value)
            return 1;
        else 
            return 0;
    } else {
        i = (begin + end) / 2;
        if (arr[i] < value) 
            return search(arr, i+1, end, value);
        else if (arr[i] > value) 
            return search(arr, begin, i-1, value);
        else 
            return 1;
    }
}