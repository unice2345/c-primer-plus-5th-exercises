/* alpha.c -- 统计字母个数 */
#include <stdio.h>
#include <ctype.h>
int main(void) 
{
    int ch;
    int upper_count = 0, lower_count = 0;
    
    while ((ch = getchar()) != EOF) {
        if (isupper(ch))
            upper_count++;
        if (islower(ch))
            lower_count++;
    }
    printf("upper_count is %d, lower_count is %d\n", upper_count, lower_count);
    printf("\n---------------------------------------------\n");
    return 0;
}