/* calc_arr2d2.c -- 对输入的二维数组进行计算 */
#include <stdio.h>
const int COLS = 5;

void populate_arr2d(double src[][COLS], int n);
double aver_arr(double src[], int n);
double aver_arr2d(double src[][COLS], int n);
double max_arr2d(double src[][COLS], int n);

void show_arr(double arr[], int n);
void show_arr2d(double arr[][COLS], int n);

int main(void) 
{
    double src[3][COLS];
    int i;
    
    populate_arr2d(src, 3);
    
    printf("average values:\n");
    for (i = 0; i < 3; i++)
        printf("%.2f ", aver_arr(src[i], COLS));
    putchar('\n');
    
    printf("average of arr2d: %.2f\n", aver_arr2d(src, 3));
    printf("max of arr2d: %.2f\n", max_arr2d(src, 3));
    
    //show_arr2d(src, 3);
    printf("\n---------------------------------------------\n");
    return 0;
}

void show_arr2d(double arr[][COLS], int n)
{
    int i;
    
    for (i = 0; i < n; i++)
        show_arr(arr[i], COLS);
}

void show_arr(double arr[], int n)
{
    int i;
    
    for (i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    putchar('\n');
}

void populate_arr2d(double src[][COLS], int n)
{
    int i, j;
    
    for (j = 0; j < n; j++) {
        printf("Input 5 numbers:");
        for (i = 0; i < COLS; i++)
            scanf("%lf", &src[j][i]);
    }
}

double aver_arr(double src[], int n)
{
    int i;
    double sum = 0;
    
    for (i = 0; i < n; i++)
        sum += src[i];
    
    return sum / n;
}

double aver_arr2d(double src[][COLS], int n)
{
    int i, j;
    double sum = 0;
    
    for (i = 0; i < n; i++) 
        for (j = 0; j < COLS; j++)
            sum += src[i][j];

    return sum / (n * COLS);
}

double max_arr2d(double src[][COLS], int n)
{
    int i, j;
    double max = src[0][0];
    
    for (i = 0; i < n; i++) 
        for (j = 0; j < COLS; j++)
            if (max < src[i][j])
                max = src[i][j];
    
    return max;
}