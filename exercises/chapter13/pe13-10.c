/* pe13-10.c -- test seek */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    long pos = 5;
    char ch;
    
    puts("Enter position, q to quit:");
    while(scanf("%ld", &pos)) {
        if ((fp = fopen("test.txt", "r")) == NULL) {
            fprintf(stderr, "Cannot open file.\n");
            exit(1);
        }
        
        fseek(fp, pos, SEEK_SET);
        while((ch = getc(fp)) != EOF && ch != '\n') {
            putchar(ch);
        }
        putchar('\n');
        puts("Enter position, q to quit:");
    }
    
    return 0;
}