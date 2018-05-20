/* menuette.c -- 菜单 */
#include <stdio.h>
char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);
int main(void) 
{
    char choice;
    
    while ((choice = get_choice()) != 'q') {
        switch (choice)
        {
            case 'a': 
                printf("Buy low, sell high.\n");
                break;
            case 'b':
                putchar('\a');
                break;
            case 'c':
                count();
                break;
            default:
                printf("Program error!\n");
                break;
        }
    }
    printf("\n---------------------------------------------\n");
    return 0;
}

char get_choice(void)
{
    char ch;
    
    printf("Enter the letter of your choice:\n");
    printf("a. advice b. bell\n");
    printf("c. count  q. quit\n");
    ch = get_first();
    while ((ch < 'a' || ch > 'c') && ch != 'q') {
        printf("Please response with a, b, c or q.\n");
        ch = getchar();
    }
    return ch;
}

char get_first(void)
{
    char ch;
    ch = getchar();
    while (getchar() != '\n')
        continue;
    return ch;
}

void count(void)
{
    int n, i;
    
    printf("Count how far? Enter an integer:\n");
    n = get_int();
    for (i = 1; i <= n; i++) 
        printf("%d ", i);
    printf("\n");
    
    while (getchar() != '\n')
        continue;
}

int get_int(void)
{
    int input;
    char ch;
    while(scanf("%d", &input) != 1) {
        while((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not an integer. Please enter an integer value.\n");
    }
    return input;
}