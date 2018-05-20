/* string_statics.c -- 统计字符串的属性 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 81
#define LIM 4
int word_count(const char* str);
int upper_count(const char* str);
int lower_count(const char* str);
int punct_count(const char* str);
int digit_count(const char* str);

int main(void) 
{
    char input[SIZE];
    char c;
    int i = 0;
    
    while ((c = getchar()) != EOF) {
        input[i++] = c;
    }
    input[i-1] = 0; // 去掉末尾的换行符。换行符和ctrl^Z共同组成了EOF
    
//    puts(input);
    printf("word count is %d\n", word_count(input));
    printf("upper count is %d\n", upper_count(input));
    printf("lower count is %d\n", lower_count(input));
    printf("punct count is %d\n", punct_count(input));
    printf("digit count is %d\n", digit_count(input));
    
    printf("\n---------------------------------------------\n");
    return 0;
}

int word_count(const char* str)
{
    int in_word;
    int count;
    
    if (*str == ' ')
        in_word = 0;
    else
        in_word = 1;
        
    count = 0;
    while(*str) {
        if (in_word && (*str == ' '))
            count ++;
        
        if (*str == ' ')
            in_word = 0;
        else
            in_word = 1;
            
        str++;
    }
    
    if (*(str-1) != ' ')
        count++;
    
    return count;
}

int upper_count(const char* str)
{
    int count = 0;
    
    while (*str) {
        if (isupper(*str))
            count++;
        str++;
    }
    
    return count;
}

int lower_count(const char* str)
{
    int count = 0;
    
    while (*str) {
        if (islower(*str))
            count++;
        str++;
    }
    
    return count;
}

int punct_count(const char* str)
{
    int count = 0;
    
    while (*str) {
        if (ispunct(*str)) {
            count++;
        }
        str++;
    }
    
    return count;
}

int digit_count(const char* str)
{
    int count = 0;
    
    while (*str) {
        if (isdigit(*str))
            count++;
        str++;
    }
    
    return count;
}