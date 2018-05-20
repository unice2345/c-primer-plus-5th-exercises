/* pe12-5.c -- 产生随机数并排序 */
#include <stdio.h>
#include <stdlib.h>

void populate_array(int array[], int n);
void sort_array(int array[], int n);
void show_array(int array[], int n);

int main(void) 
{
    int array[100];
    
    populate_array(array, 100);
    sort_array(array, 100);
    show_array(array, 100);
    
    printf("\n---------------------------------------------\n");
    return 0;
}

void populate_array(int array[], int n)
{
    int i;
    
    for (i = 0; i < n; i++)
        array[i] = rand() % 100;
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