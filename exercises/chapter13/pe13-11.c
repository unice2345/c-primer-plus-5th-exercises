/* pe13-11.c -- print line */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1024
int main(int argc, char *argv[])
{
    FILE *fp;
    char line[MAXLINE];
    //char substr[MAXLINE];
    
    if (argc < 3) {
        fprintf(stderr, "Usage: %s string file_name\n", argv[0]);
        exit(1);
    }
    
    if ((fp = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Cannot open file %s.\n", argv[2]);
        exit(1);
    }
    
    while (fgets(line, MAXLINE, fp) != NULL) {
        if (strstr(line, argv[1]) != NULL)
            fputs(line, stdout);
    }
    putchar('\n');
    
    return 0;
}