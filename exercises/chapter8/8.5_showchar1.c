/* showchar1.c -- 带有一个较大I/O问题的程序 */
#include <stdio.h>
void display(char cr, int lines, int width);
int main(void) 
{
    int cr;
    int rows, cols;
    printf("Enter a character and tow integers:\n");
    while ((cr = getchar()) != '\n') {
        scanf("%d%d", &rows, &cols);
        display(cr, rows, cols);
        printf("Enter a character and tow integers:\n");
        printf("Enter a new line to quit.\n");
        
        while (getchar() != '\n')
            continue;
    }
    printf("\n---------------------------------------------\n");
    return 0;
}

void display(char cr, int lines, int width)
{
    int row, col;
    for (row = 0; row < lines; ++row) {
        for (col = 0; col < width; ++col) 
            printf("%c", cr);
        printf("\n");
    }
}