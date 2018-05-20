/* pe13-1.c -- 使用标准I/O */
#include <stdio.h>
#include <stdlib.h> // exit()原型

int main(int argc, char *argv[]) 
{
    int ch;               // 读取时存储每个字符
    FILE* fp;             // 文件指针
    long count = 0;
    char filename[80];
    
    printf("Input file of which you want to open: ");
    scanf("%s", filename);
    
    if (NULL == (fp = fopen(filename, "r"))) {
        printf("Can't open %s\n", filename);
        exit(1);
    }
    
    while ((ch = getc(fp)) != EOF) {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("\nFile %s has %ld characters\n", filename, count);
    
    printf("\n---------------------------------------------\n");
    return 0;
}