/* pe16-5.c -- randow select */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

/**
 * @brief 从数组中随机选取一定数量的元素并打印
 * @param arr 数组
 * @param count 数组大小
 * @param n 选取的元素数量
 */
void random_select(int arr[], int count, int n);

int main(void) 
{
    int arr[SIZE];
    int i;
    
    for (i = 0; i < SIZE; i++)
        arr[i] = i;
    
    random_select(arr, SIZE, 5);
    printf("\n---------------------------------------------\n");
    return 0;
}

void random_select(int arr[], int count, int n)
{
    int i;
    int select[1024] = {0};
    int index;
    
    srand(time(0));
    for (i = 0; i < n; i++) {
        index = rand() % count;
        while (select[index] != 0) {
            index = rand() % count;
        }
        select[index] = 1;
        printf("%d ", arr[index]);
    }
    putchar('\n');
}