/* calc_arr2d.c -- 对输入的二维数组进行计算 */
#include <stdio.h>

void populate_arr2d(int rows, int cols, double src[rows][cols]);
double aver_arr(int n, double src[n]);
double aver_arr2d(int rows, int cols, double src[rows][cols]);
double max_arr2d(int rows, int cols, double src[rows][cols]);

int main(void) 
{
    int rows = 3, cols = 5;
    double src[rows][cols];
    int i;
    
    populate_arr2d(rows, cols, src);
    
    printf("average values:\n");
    for (i = 0; i < rows; i++)
        printf("%.2f ", aver_arr(cols, src[i]));
    putchar('\n');
    
    printf("average of arr2d: %.2f\n", aver_arr2d(rows, cols, src));
    printf("max of arr2d: %.2f\n", max_arr2d(rows, cols, src));
    
    printf("\n---------------------------------------------\n");
    return 0;
}


void populate_arr2d(int rows, int cols, double src[rows][cols])
{
    int i, j;
    
    for (j = 0; j < rows; j++) {
        printf("Input 5 numbers:");
        for (i = 0; i < cols; i++)
            scanf("%lf", &src[j][i]);
    }
}

double aver_arr(int n, double src[n])
{
    int i;
    double sum = 0;
    
    for (i = 0; i < n; i++)
        sum += src[i];
    
    return sum / n;
}

double aver_arr2d(int rows, int cols, double src[rows][cols])
{
    int i, j;
    double sum = 0;
    
    for (i = 0; i < rows; i++) 
        for (j = 0; j < cols; j++)
            sum += src[i][j];

    return sum / (rows * cols);
}

double max_arr2d(int rows, int cols, double src[rows][cols])
{
    int i, j;
    double max = src[0][0];
    
    for (i = 0; i < rows; i++) 
        for (j = 0; j < cols; j++)
            if (max < src[i][j])
                max = src[i][j];
    
    return max;
}