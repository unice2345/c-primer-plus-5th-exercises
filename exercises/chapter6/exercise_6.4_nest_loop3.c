/* nest_loop3.c -- 嵌套循环打印图案 */
#include <stdio.h>

int main(void) 
{
    int count;
    int i, j;
    char c;
    printf("Enter an character:");
    scanf("%c", &c);
    
    count = c - 'A' + 1;
    for(i = 0; i < count; i++) {
        for(j = i; j < count-1; j++) { // 打印空格
            printf(" ");
        }
        for(j = 0; j <= i; j++) { // 升序打印字母
            printf("%c", 'A'+j);
        }
        for(j = i; j > 0; j--) { // 降序打印字母
            printf("%c", 'A' + j - 1);
        }
        printf("\n");
    }
    

    return 0;
}