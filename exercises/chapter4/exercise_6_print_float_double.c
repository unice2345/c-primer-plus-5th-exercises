/* print_float_double.c -- 按格式输出float和double值 */
#include <stdio.h>
#include <float.h>

int main(void)
{
    float f= 1.0/3.0;
    double d = 1.0/3.0;
    
    printf("float: %.4f, %.12f, %.16f\n", f, f, f);
    printf("double: %.4f, %.12f, %.16f\n", d, d, d);
    printf("FLT_DIG = %d, DBL_DIG = %d\n", FLT_DIG, DBL_DIG); 
    return 0;
}