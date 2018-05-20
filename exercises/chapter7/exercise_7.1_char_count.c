/* char_count.c -- 对输入字符进行计数 */
#include <stdio.h>

int main(void) 
{
    int space_count = 0, new_line_count = 0, other_count = 0;
    char ch;
    
    while ((ch = getchar()) != '#') {
        if (ch == ' ')
            space_count++;
        else if (ch == '\n')
            new_line_count++;
        else
            other_count++;
    }
    
    printf("You entered %d spaces, %d new lines and %d other chars.\n",
        space_count, new_line_count, other_count);
    printf("\n---------------------------------------------\n");
    return 0;
}