/* pe13.4_print_files.c -- 打印所有文件内容 */
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 20

void print_file(FILE* fp);

int main(int argc, char *argv[])
{
    int i;
    FILE* fp;
    
    for (i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("\nCan't open %s\n", argv[i]);
            exit(1);
        }
        printf("\nFile %s content:\n", argv[i]);
        print_file(fp);
        fclose(fp);
    }
    
    return 0;
}

void print_file(FILE* fp)
{
    char line[MAXLINE];
    
    while (fgets(line, MAXLINE, fp) != NULL)
        fputs(line, stdout);
}