/* ei_count.c -- 统计ei出现的次数 */
#include <stdio.h>

int main(void) 
{
    char ch, prev_ch = 0;
    int count = 0;
    
    while ((ch = getchar()) != '#') {
        if (prev_ch == 'e' && ch == 'i')
            count++;
        prev_ch = ch;
    }
    printf("There are %d ei.", count);
    printf("\n---------------------------------------------\n");
    return 0;
}