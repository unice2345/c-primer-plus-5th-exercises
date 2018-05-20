/* printname2.c -- 按指定格式打印输入的名字 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char first_name[30];
    printf("Input your first name:");
    scanf("%s", first_name);
    printf("\"%s\"\n", first_name);
    printf("\"%20s\"\n", first_name);
    printf("\"%-20s\"\n", first_name);
    printf("\"%*s\"\n", strlen(first_name) + 3, first_name);
    return 0;
}