/* pe16-7.c -- 可变参数 */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
void show_array(const double ar[], int n);
double * new_d_array(int n, ...);

int main(void) 
{
    double * p1, * p2;
    
    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.0, 8.08, -1890.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);
    printf("\n---------------------------------------------\n");
    return 0;
}

void show_array(const double ar[], int n)
{
    int i;
    
    for (i = 0; i < n; i++) {
        printf("%.2f ", ar[i]);
    }
    putchar('\n');
}

double * new_d_array(int n, ...)
{
    va_list va;
    int i;
    double * ar = (double *)malloc(n * sizeof(double));
    
    va_start(va, n);
    for (i = 0; i < n; i++) {
        ar[i] = va_arg(va, double);
    }
    va_end(va);
    
    return ar;
}