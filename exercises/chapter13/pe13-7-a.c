#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1024

int is_end_new_line(char line[])
{
    int len = strlen(line);
    if (len > 0)
        return line[len-1] == '\n';
    else 
        return 0;
}

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char line1[MAXLINE], line2[MAXLINE];
    char *ptr1, *ptr2;
    int count = 0;
    
    if (argc < 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(1);
    }
    
    // Open file
    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", argv[1]);
        exit(1);
    }
    if ((fp2 = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", argv[2]);
        fclose(fp1);
        exit(2);
    }
    
    // Print file content
    ptr1 = fgets(line1, MAXLINE, fp1) ;
    ptr2 = fgets(line2, MAXLINE, fp2) ;
    
    while (ptr1 || ptr2) {
        
        //printf(" count = %d: ", count++);
        if (ptr1 != NULL) {
            fputs(line1, stdout);
        
            if (!is_end_new_line(line1))
                putchar('\n');
        }
        if (ptr2 != NULL) {
            fputs(line2, stdout);
            
            if (!is_end_new_line(line2))
                putchar('\n');
        }
            
        ptr1 = fgets(line1, MAXLINE, fp1) ;
        ptr2 = fgets(line2, MAXLINE, fp2) ;
    }
    
    // Close files
    fclose(fp1);
    fclose(fp2);
    return 0;
}