/* pe13-2.c -- file copy */
#include <stdio.h>
#include <Stdlib.h>

int main(int argc, char *argv[])
{
    FILE *in, *out;
    char ch;
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s in_file out_file\n", argv[0]);
        exit(1);
    }
    
    if ((in = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(1);
    }
    if ((out = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        exit(1);
    }
    
    while ((ch = getc(in)) != EOF) {
        putc(ch, out);
    }
    
    fclose(in);
    fclose(out);
    return 0;
}