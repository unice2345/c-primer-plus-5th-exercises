/* printfloat.c -- 打印浮点数 */
#include <stdio.h>
float calcNormalSub(float x, float y);
int main(void) 
{
    float x, y;
    printf("Enter two float values:");
    while(2 == scanf("%f %f", &x, &y)) {
        //printf("(%f-%f)/(%f * %f)) is %f\n", x, y, x, y, (x - y)/ (x * (double)y));
        printf("(%f-%f)/(%f * %f)) is %f\n", x, y, x, y, calcNormalSub(x,y));
        printf("Enter two another float values:");
    }
    return 0;
}

float calcNormalSub(float x, float y)
{
    return (x - y)/ (x * (double)y);
}