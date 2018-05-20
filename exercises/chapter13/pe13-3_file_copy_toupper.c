/* pe13-3.c -- file copy to upper */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *in, *out;
    char ch;
    char in_file[80];
    char out_file[80];
    
    printf("Input in file and out file: ");
    scanf("%s %s", in_file, out_file);
    
    if ((in = fopen(in_file, "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", in_file);
        exit(1);
    }
    if ((out = fopen(out_file, "w")) == NULL) {
        fprintf(stderr, "Can't open %s\n", out_file);
        exit(1);
    }
    
    while ((ch = getc(in)) != EOF) {
        putc(toupper(ch), out);
    }
    
    fclose(in);
    fclose(out);
    return 0;
}