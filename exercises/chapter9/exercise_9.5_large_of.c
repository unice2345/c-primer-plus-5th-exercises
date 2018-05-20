/* large_of.c -- 替换成大值 */
#include <stdio.h>
void large_of(double * x, double * y);
int main(void) 
{
    double x = 2.0, y = 4.0;
    large_of(&x, &y);
    printf("x = %.2f, y = %.2f.", x, y);
    printf("\n---------------------------------------------\n");
    return 0;
}

void large_of(double * x, double * y)
{
    (*x > *y) ? (*y = *x) : (*x = *y);
    
    //double large = (*x > *y) ? *x : *y;
    //*x = large;
    //*y = large;
    
      
}