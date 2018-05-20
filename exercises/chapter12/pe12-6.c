/* pe12-6.c -- 产生随机数并排序 */
#include <stdio.h>
#include <stdlib.h>

void rand_array(int array[], int n, int seed);
void sort_array(int array[], int n);
void show_array(int array[], int n);

int main(void) 
{
    int array[10];
    //int seed;
    int i;
    
    for (i = 0; i < 10; i++) {
        rand_array(array, 10, i);
        show_array(array, 10);
    }
    
    printf("\n---------------------------------------------\n");
    return 0;
}

void rand_array(int array[], int n, int seed)
{
    int i;
    
    for (i = 0; i < n; i++)
        array[i] = 0;
        
    srand(seed);
    for (i = 0; i < 1000; i++) {
        array[rand() % n]++;
    }
}

void show_array(int array[], int n)
{
    int i;
    
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
        if ((i+1) % 10 == 0)
            printf("\n");
    }
    printf("\n");
}

void sort_array(int array[], int n)
{
    int i, j, tmp;
    
    for (i = 1; i < n; i++) {
        for (j = 0; j < n-i; j++) {
            if (array[j] < array[j+1]) {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}