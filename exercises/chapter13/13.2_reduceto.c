#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
int main(void)
{
    char name[LEN];
    char name2[LEN];
    FILE *in, *out;
    char ch;
    int count = 0;
    
    printf("Input file name:");
    scanf("%s", name);
    
    if ((in = fopen(name, "r")) == NULL) {
        printf("Can't open file %s\n", name);
        exit(1);
    }
    
    strcpy(name2, name);
    strcat(name2, ".red");
    
    if ((out = fopen(name2, "w")) == NULL) {
        printf("Can't open file %s\n", name2);
        exit(2);
    }
    
    while ((ch = getc(in)) != EOF) {
        if (count++ % 3 == 0)
            putc(ch, out);
    }
    
    fclose(in);
    fclose(out);
    return 0;
}
