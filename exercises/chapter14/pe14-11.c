
#include <stdio.h>
#include <math.h>
void transform(double source[], double target[], int n, double (*pfun)(double));

double add(double x) {
    return x + 10;
}

double mul(double x) {
    return x * 2;
}

void show(double arr[], int n);

int main(void)
{
    double source[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double target[100];
    
    transform(source, target, 100, add);
    show(target, 10);
    transform(source, target, 100, mul);
    show(target, 10);
    transform(source, target, 100, sin);
    show(target, 10);
    transform(source, target, 100, cos);
    show(target, 10);
    
    return 0;
}

void transform(double source[], double target[], int n, double (*pfun)(double))
{
    int i;
    
    for (i = 0; i < n; i++) {
        target[i] = pfun(source[i]);
    }
}

void show(double arr[], int n)
{
    int i;
    
    for (i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
        if (i > 1 && i % 10 == 0)
            putchar('\n');
    }
    putchar('\n');
}