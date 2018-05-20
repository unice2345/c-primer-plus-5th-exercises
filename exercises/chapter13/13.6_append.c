#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024
#define SLEN 81

void append(FILE* source, FILE* dest);

int main(void)
{
    FILE* fa, *fs;
    int files = 0;
    char file_app[SLEN];
    char file_src[SLEN];
    puts("Enter name of destination file:");
    gets(file_app);
    if ((fa = fopen(file_app, "a")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", file_app);
        exit(2);
    }
    
    puts("Enter name of first source file (empty line to quit):");
    while (gets(file_src) && file_src[0] != '\0') {
        if (strcmp(file_app, file_src) == 0) 
            fputs("Can't append file to itself\n", stderr);
        else if ((fs = fopen(file_src, "r")) == NULL)
            fprintf(stderr, "Can't open file %s\n", file_src);
        else {
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s\n", file_src);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s\n", file_app);
            
            fclose(fs);
            files++;
            printf("File %s appended.\n", file_src);
            puts("Next file (empty line to quit):");
        }
    }
}

void append(FILE* source, FILE* dest)
{
    size_t bytes;
    static char temp[BUFSIZ];
    
    while ((bytes = fread(temp, BUFSIZE, sizeof(char), source)) > 0) 
        fwrite(temp, sizeof(char), bytes, dest);
}