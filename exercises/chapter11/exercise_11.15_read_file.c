/* read_file.c -- 读取文件 */
#include <stdio.h>
#include <ctype.h>

void print();
void print_upper();
void print_lower();

int main(int argc, char* argv[]) 
{
    switch(argv[1][1]) {
        case 'p':
            print();
            break;
        case 'u':
            print_upper();
            break;
        case 'l':
            print_lower();
            break;
    }
    //print();
    printf("\n---------------------------------------------\n");
    return 0;
}

void print()
{
    char c;
    while ((c = getchar()) != EOF)
        putchar(c);
}

void print_upper()
{
    char c;
    while ((c = getchar()) != EOF)
        putchar(toupper(c));
}

void print_lower()
{
    char c;
    while ((c = getchar()) != EOF)
        putchar(tolower(c));
}