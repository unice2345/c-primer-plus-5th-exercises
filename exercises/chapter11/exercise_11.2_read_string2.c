/* read_string2.c -- 读取字符串 */
#include <stdio.h>

/**
 * @brief 从输入读取字符串到数组中
 * @param str 字符串数组，保存读入的字符串
 * @param n 读入的字符个数
 */
void read_string(char str[], int n);

int main(void) 
{
    char str[32];
    read_string(str, 5);
    printf("%s", str);
    printf("\n---------------------------------------------\n");
    return 0;
}

void read_string(char str[], int n)
{
    int i = 0;
    
    while ((i < n) && (str[i] = getchar()) && str[i] != ' ' && str[i] != '\n' && str[i] != '\b')
        i++;
    str[i] = '\0';
}