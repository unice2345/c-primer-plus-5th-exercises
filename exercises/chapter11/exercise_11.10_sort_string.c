/* sort_string.c -- 字符串排序 */
#include <stdio.h>
#include <string.h>
#define SIZE 81
#define LIM 10

/**
 * @brief 返回字符串中的第一个单词的长度
 * @param str0 字符串
 * @return 第一个单词的长度
 */
int first_word_len(const char * str0);

void sort_strings_by_alpha(const char* strings[], int num);
void sort_strings_by_len(const char* strings[], int num);
void sort_strings_by_first_word_len(const char* strings[], int num);

void menu(void);

void print_strings(const char* str[], int num);
void print_string_array(char strings[][SIZE], int num);

int main(void) 
{
    char strings[LIM][SIZE];
    const char* ptr_str[SIZE];
    int i = 0;
    char choice;
    
    printf("Please input %d strings:\n", LIM);
    // 读取字符串
    while ( (i < LIM) && (ptr_str[i] = gets(strings[i])) )
        i++;
    
    menu();
    
    while( (choice = getchar()) != EOF && choice != 'q') {
        
        while (getchar() != '\n')
            continue;
            
        switch (choice) {
            case 'a':
                print_string_array(strings, LIM);
                break;
            case 'b':
                sort_strings_by_alpha(ptr_str, LIM);
                print_strings(ptr_str, LIM);
                break;
            case 'c':
                sort_strings_by_len(ptr_str, LIM);
                print_strings(ptr_str, LIM);
                break;
            case 'd':
                sort_strings_by_first_word_len(ptr_str, LIM);
                print_strings(ptr_str, LIM);
                break;
            case 'q':
            default:
                printf("Unknonw choice!\n");
                break;
        }
        
        menu();
    } 
    
    printf("\n---------------------------------------------\n");
    return 0;
}

int first_word_len(const char * str0)
{
    int count = 0;
    
    // 找到第一个非空格的字符
    while (*str0 == ' ')
        str0++;
    
    while (*str0 && *str0 != ' ') {
        str0++;
        count++;
    }
    
    return count;
}

void sort_strings_by_alpha(const char* strings[], int num)
{
    int i, j;
    const char* ptr_tmp;
    
    for (i = 1; i < num; i++) {
        for (j = 0; j < num-i; j++) {
            if (strcmp(strings[j], strings[j+1]) > 0) {
                ptr_tmp = strings[j];
                strings[j] = strings[j+1];
                strings[j+1] = ptr_tmp;
            }
        }
    }
}

void sort_strings_by_len(const char* strings[], int num)
{
    int i, j;
    const char* ptr_tmp;
    
    for (i = 1; i < num; i++) {
        for (j = 0; j < num-i; j++) {
            //if (strcmp(strings[j], strings[j+1]) > 0) {
            if ( strlen(strings[j]) > strlen(strings[j+1]) ) {
                ptr_tmp = strings[j];
                strings[j] = strings[j+1];
                strings[j+1] = ptr_tmp;
            }
        }
    }
}

void sort_strings_by_first_word_len(const char* strings[], int num)
{
    int i, j;
    const char* ptr_tmp;
    
    for (i = 1; i < num; i++) {
        for (j = 0; j < num-i; j++) {
            //if (strcmp(strings[j], strings[j+1]) > 0) {
            //if ( strlen(strings[j]) > strlen(strings[j+1]) ) {
            if ( first_word_len(strings[j]) > first_word_len(strings[j+1]) ) {
                ptr_tmp = strings[j];
                strings[j] = strings[j+1];
                strings[j+1] = ptr_tmp;
            }
        }
    }
}

void menu(void)
{
    printf("**************************************************************\n");
    printf("a. Print strings            b. Print strings by alpha\n");
    printf("c. Print strings by len     d. Print strings by first word len\n");
    printf("q. Quit\n");
    printf("**************************************************************\n");
}

void print_strings(const char* str[], int num)
{
    int i;
    
    for (i = 0; i < num; i++)
        puts(str[i]);
}

void print_string_array(char strings[][SIZE], int num)
{
    int i;
    
    for (i = 0; i < num; i++)
        puts(strings[i]);
}