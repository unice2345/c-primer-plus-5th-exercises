/* pe13-9.c -- addword */
#include <stdio.h>
#include <stdlib.h>
#define MAX 40
int main(void)
{
    FILE* fp;
    char words[MAX];
    int count = 0;
    
    if ((fp = fopen("words.txt", "a+")) == NULL) {
        fprintf(stderr, "Can't open file.\n");
    }
    
    // get count
    //while (fgets(words, MAX, fp) != NULL) {
    while(fscanf(fp, "%s", words) > 0) {
       puts(words);
       count++;
    }
    count /= 2;
    if (count > 0)
        printf("%d words.\n", count);    
    
    puts("Enter words and add to the file; press ctrl^Z to terminate.\n");
    //while (gets(words) != NULL && words[0] != '\0') {
    while (scanf("%s", words) > 0) {
        fprintf(fp, "%d %s ", count++, words);
    }
    puts("File content:\n");
    rewind(fp);
    while (fscanf(fp, "%s", words) == 1)
        //fputs(words, stdout);
        puts(words);
    fclose(fp);
    
    return 0;
}
