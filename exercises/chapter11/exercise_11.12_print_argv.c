/* print_arv.c -- 打印输入参数 */
#include <stdio.h>

int main(int argc, char* argv[]) 
{
    int i;
    
    for (i = argc; i > 1; i--)
        printf("%s ", argv[i-1]);
            //printf("%d %s ", i-1, "hello");
    
    printf("\n---------------------------------------------\n");
    return 0;
}