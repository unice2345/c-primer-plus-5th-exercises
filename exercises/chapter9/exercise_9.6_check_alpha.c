/* check_alpha.c -- 判断字符是否是字母，并给出字母的位置 */
#include <stdio.h>
int check_alpha(char ch);
int main(void) 
{
    char ch;
    int pos;
    
    while (scanf("%c", &ch) != EOF) {
        if (ch == '\n') 
            continue; // 不检查空格符
        pos = check_alpha(ch);
        if (pos > 0) {
            printf("%c is alpha and it's position is %d\n", ch, pos);
        } else {
            printf("%c is not alpha.\n", ch);
        }
    }
    printf("\n---------------------------------------------\n");
    return 0;
}

int check_alpha(char ch)
{
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 1;
    }
    
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 1;
    }
    
    return -1;
}