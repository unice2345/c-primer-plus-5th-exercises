/* word_count.c -- 统计单词中平均字母个数 */
#include <stdio.h>
#include <ctype.h>
int main(void) 
{
    int ch;
    int word_count = 0;
    int char_count = 0;
    int total_char_count = 0;
    
    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            char_count++;
        } else {
            if (char_count > 0) {
                word_count++;
                total_char_count += char_count;
            }
            char_count = 0;
        }
    }
    printf("word_count is %d, aver char count per word is %.2f", word_count, total_char_count * 1.0 / word_count);
    printf("\n---------------------------------------------\n");
    return 0;
}