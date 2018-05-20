/* printname.c -- 打印输入的名字 */
#include <stdio.h>

int main(void)
{
    char first_name[30], last_name[30];
    printf("Input your name:");
    scanf("%s", first_name);
    scanf("%s", last_name);
    printf("Welcome, %s %s\n", first_name, last_name);
    return 0;
}