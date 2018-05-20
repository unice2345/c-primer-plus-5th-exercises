#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024
#define SLEN 81

void append(FILE* source, FILE* dest);

int main(int argc, char *argv[])
{
    
    FILE* fa, *fs;
    int files = 0;
    const char* file_app;
    const char* file_src;
    int i;
    
    if (argc < 3) {
        fprintf(stderr, "Usage: %s file_app file_src [...]\n", argv[0]);
        exit(1);
    }
    
    file_app = argv[1];
    if ((fa = fopen(file_app, "ab")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", file_app);
        exit(2);
    }
    
    for (i = 2; i < argc; i++) 
    {
        file_src = argv[i];
        if (strcmp(file_app, file_src) == 0) 
            fputs("Can't append file to itself\n", stderr);
        else if ((fs = fopen(file_src, "rb")) == NULL)
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
        }
    }
    printf("Done. %d files appended.\n", files);
    fclose(fa);
    return 0;
}

void append(FILE* source, FILE* dest)
{
    size_t bytes;
    static char temp[BUFSIZE];
//    size_t ret_code;
//    int i;
//    
    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0) {
    //while ((bytes = fread(temp, BUFSIZE, sizeof(char), source)) > 0) {
        fwrite(temp, sizeof(char), bytes, dest);
    }
    
//    ret_code = fread(temp, BUFSIZE, sizeof(char), source);
//    if (ret_code == BUFSIZE) {
//        puts("Read successfully, content: \n");
//        for (i = 0; i < BUFSIZE; i++)
//            putchar(temp[i]);
//        putchar('\n');
//    } else {
//        if (feof(source)) {
//            printf("Error: unexpected end of file.\n");
//            printf("%d count read.\n", ret_code);
//            for (i = 0; i < BUFSIZE; i++)
//                putchar(temp[i]);
//            putchar('\n');
//        }
//        else if (ferror(source)) 
//            printf("Error reading file.\n");
//    }
}