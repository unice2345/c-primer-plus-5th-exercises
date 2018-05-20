/* print_name_count.c -- 按格式输出名字和长度 */
#include <stdio.h>
#include <string.h>
int main(void)
{
    char first_name[20];
    char last_name[20];
    int first_name_length, last_name_length;
    printf("Input your name:");
    scanf("%s %s", first_name, last_name);
    printf("%s %s\n", first_name, last_name);
    first_name_length = strlen(first_name);
    last_name_length = strlen(last_name);
    printf("%*d %*d\n", first_name_length, first_name_length, last_name_length, last_name_length);
    
    printf("%s %s\n", first_name, last_name);
    printf("%-*d %-*d\n", first_name_length, first_name_length, last_name_length, last_name_length);
    return 0;
}