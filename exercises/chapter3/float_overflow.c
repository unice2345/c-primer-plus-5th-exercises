/* float_overflow.c -- 测试浮点数上溢和下溢 */
#include <stdio.h>

int main(void)
{
    float toobig = 3.4E38 * 100.0f;
    double toosmall = 2.2250738585072014E-308 / 10;
    printf("toobig is %e\n", toobig);
    printf("toosmall is %e\n", toosmall);
    return 0;
}