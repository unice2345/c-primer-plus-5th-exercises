/* count.c -- 使用标准I/O */
#include <stdio.h>
#include <stdlib.h> // exit()原型

int main(int argc, char *argv[]) 
{
    int ch;               // 读取时存储每个字符
    FILE* fp;             // 文件指针
    long count = 0;
    
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }
    
    if (NULL == (fp = fopen(argv[1], "r"))) {
        printf("Can't open %s\n", argv[1]);
        exit(1);
    }
    
    while ((ch = getc(fp)) != EOF) {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("\nFile %s has %ld characters\n", argv[1], count);
    
    printf("\n---------------------------------------------\n");
    return 0;
}