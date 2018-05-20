/* pe14-10.c -- menu */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
char showmenu(void);
void eatline(void);

void fun0() { printf("Oh, this fun0\n");}
void fun1() { printf("Oh, this fun1\n");}
void fun2() { printf("Oh, this fun2\n");}
void fun3() { printf("Oh, this fun3\n");}

int main(void) 
{
    char choice;
    typedef void (*FUNC)();
    FUNC funcs[4] = {fun0, fun1, fun2, fun3};
    
    choice = showmenu();
    
    //printf("Your choice is %c\n", choice);
    switch (choice) {
        case 'a': funcs[0](); break;
        case 'b': funcs[1](); break;
        case 'c': funcs[2](); break;
        case 'd': funcs[3](); break;
        case 'q':
        default: printf("Bye\n"); break;
    }
    printf("\n---------------------------------------------\n");
    return 0;
}

char showmenu(void)
{
    char choice;
    
    printf("Enter choice:\n");
    printf("a...     b...\n");
    printf("c...     d...\n");
    printf("q. quit\n");
    choice = getchar();
    eatline();
    while(strchr("abcdq", choice) == NULL) {
        printf("Please enter a, b, c, d or q:");
        choice = getchar();
        eatline();
    }
    return choice;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}