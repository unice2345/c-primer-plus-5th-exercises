/* pe13-12.c.c -- digital_image */
#include <stdio.h>
#include <stdlib.h>
#define NUM 30
#define LINE 20
int main(void) 
{
    FILE* fp;
    int num[LINE][NUM];
    char chars[LINE][NUM];
    int i, j;
    char toChars[10] = " .':~*= %#";
    
    
    fp = fopen("image.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file\n");
        exit(1);
    }
    
    for (i = 0; i < LINE; i++) {
        for (j = 0; j < NUM; j++) {
            fscanf(fp, "%d", &num[i][j]);
            chars[i][j] = toChars[num[i][j]];
        }
    }
    
    for (i = 0; i < LINE; i++) {
        for (j = 0; j < NUM; j++) {
            //printf("%d ", num[i][j]);
            putchar(chars[i][j]);
        }
        putchar('\n');
    }
    
    fclose(fp);
    
    printf("\n---------------------------------------------\n");
    return 0;
}