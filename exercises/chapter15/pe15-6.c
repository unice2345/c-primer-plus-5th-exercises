/* pe15-6.c -- 程序的功能 */
#include <stdio.h>
#include <string.h>
/* alignment */
#define LEFT 0
#define CENTER 1
#define RIGHT 2
/* */
#define OFF 0
#define ON 1

struct font {
    unsigned int id: 8;
    unsigned int size: 7;
    unsigned int alignment: 2;
    unsigned int bold: 1;
    unsigned int italic: 1;
    unsigned int underline: 1;
};

void show_font(struct font* pfont);
char get_choice();
void eat_line();

void change_font(struct font* pfont);
void change_size(struct font* pfont);
void change_alignment(struct font* pfont);
void toggle_bold(struct font* pfont);
void toggle_italic(struct font* pfont);
void toggle_underline(struct font* pfont);

int main(void) 
{
    struct font font0 = {1, 12, LEFT, OFF, OFF, OFF};
    char choice;
    
    show_font(&font0);
    while((choice = get_choice()) && (choice != 'q')) {
        switch (choice) {
            case 'f':
                change_font(&font0);
                show_font(&font0);
                break;
            case 's':
                change_size(&font0);
                show_font(&font0);
                break;
            case 'a':
                change_alignment(&font0);
                show_font(&font0);
                break;
            case 'b':
                toggle_bold(&font0);
                show_font(&font0);
                break;
            case 'i':
                toggle_italic(&font0);
                show_font(&font0);
                break;
            case 'u':
                toggle_underline(&font0);
                show_font(&font0);
                break;
        }
    }
    puts("Bye.");
    return 0;
}

void show_font(struct font* pfont)
{
    static char* alignments[3] = {
        "left",
        "center",
        "right"
    };
    
    puts("ID  SIZE  ALIGNMENT  B  I  U");
    printf("%d  ", pfont->id);
    printf("%d  ", pfont->size);
    printf("%s  ", alignments[pfont->alignment]);
    printf("%s  ", pfont->bold ? "on" : "off");
    printf("%s  ", pfont->italic ? "on" : "off");
    printf("%s\n", pfont->underline ? "on" : "off");
}

char get_choice()
{
    char choice;
    
    puts("f) change font  s) change size  a) change alignment");
    puts("b) toggle bold  i) toggle itatlic  u) toggle underline");
    puts("q) quit");
    
//    while(scanf("%c", &choice)) {
//        eat_line();
//        printf("choice is %c\n", choice);
//        if (strchr("fsabiuq", choice) == NULL) {
//            puts("Please enter f, s, a, b, i, u or q");
//        } else {
//            break;
//        }
//    }

    choice = getchar();
    eat_line();
    
    while (strchr("fsabiuq", choice) == NULL) {
        puts("Please enter f, s, a, b, i, u or q");
        choice = getchar();
        eat_line();
    }
    
    return choice;
}

void eat_line()
{
    while(getchar() != '\n')
        continue;
}

void change_font(struct font* pfont)
{
    int id;
    puts("Enter font id (0-255):");
    scanf("%d", &id);
    eat_line();
    pfont->id = id;
}

void change_size(struct font* pfont) {
    int size;
    puts("Enter font size (0-127):");
    scanf("%d", &size);
    eat_line();
    pfont->size = size;
}

void change_alignment(struct font* pfont)
{
    char alignment;
    puts("Select alignment:");
    puts("l)left   c)center   r)right");
    alignment = getchar();
    eat_line();
    
    while (strchr("lcr", alignment) == NULL) {
        puts("Please enter l, c, or r");
        alignment = getchar();
        eat_line();
    }
    
    switch (alignment) {
        case 'l':
            pfont->alignment = LEFT;
            break;
        case 'c':
            pfont->alignment = CENTER;
            break;
        case 'r':
            pfont->alignment = RIGHT;
            break;
    }
}

void toggle_bold(struct font* pfont)
{
    pfont->bold = ~(pfont->bold);
}

void toggle_italic(struct font* pfont)
{
    pfont->italic = ~(pfont->italic);
}

void toggle_underline(struct font* pfont)
{
    pfont->underline = ~(pfont->underline);
}