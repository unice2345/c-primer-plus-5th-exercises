/* pe14-8.c -- 统计文件中的字符数目 */
#include <stdio.h>
#include <stdlib.h>

int count_character_in_file(FILE* fp, char ch);

int main(int argc, char *argv[])
{
    FILE* fp;
    char ch;
    int i;
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s character file_name\n", argv[0]);
        exit(1);
    }
    
    ch = argv[1][0];
    
    if (argc == 2) {
        printf("File stdin contain %d %c\n", count_character_in_file(stdin, ch), ch);
    } else {
        for (i = 2; i < argc; i++) {
            fp = fopen(argv[i], "r");
            if (fp == NULL) {
                fprintf(stderr, "Cannot open file %s\n", argv[i]);
                continue;
            }
            printf("File %s contain %d %c\n", argv[i], count_character_in_file(fp, ch), ch);
            fclose(fp);
        }
    }
    return 0;
}

int count_character_in_file(FILE* fp, char ch)
{
    int count = 0;
    char read_ch;
    
    while ((read_ch = getc(fp)) != EOF) {
        if (read_ch == ch)
            count++;
    }
    
    return count;
}
