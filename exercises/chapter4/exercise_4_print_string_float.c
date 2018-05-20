/* print_string_float.c -- 打印字符串和浮点数 */
#include <stdio.h>

int main(void)
{
    char name[20];
    float height;
    printf("Input your name and height:");
    scanf("%s %f", name, &height);
    printf("%s, you are %.3f feet tall.\n", name, height);
    return 0;
}