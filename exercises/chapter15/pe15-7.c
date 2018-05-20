/* pe15-7.c -- 程序的功能 */
#include <stdio.h>
#include <string.h>

#define ID_MASK 0xff
#define SIZE_MASK 0x7f00
#define SIZE_OFFSET 8
#define ALIGNMENT_LEFT 0x8000
#define ALIGNMENT_CENTER 0x10000
#define ALIGNMENT_RIGHT 0x18000
#define ALIGNMENT_MASK 0x18000
#define ALIGNMENT_OFFSET 15
#define BOLD_MASK 0x20000
#define BOLD_OFFSET 17
#define ITALIC_MASK 0x40000
#define ITALIC_OFFSET 18
#define UNDERLINE_MASK 0x80000
#define UNDERLINE_OFFSET 19

void show_font(unsigned long * pfont);
void set_font_id(unsigned long * pfont, int id);
void set_font_size(unsigned long * pfont, int size);
void set_font_alignment(unsigned long * pfont, int alignment);

char get_choice();
void eat_line();

void change_font(unsigned long * pfont);
void change_size(unsigned long * pfont);
void change_alignment(unsigned long * pfont);
void toggle_bold(unsigned long * pfont);
void toggle_italic(unsigned long * pfont);
void toggle_underline(unsigned long * pfont);

int main(void) 
{
    unsigned long font = 0;
    char choice;
    
    set_font_id(&font, 255);
    set_font_size(&font, 127);
    
    font &= ~ALIGNMENT_MASK;
    font |= ALIGNMENT_RIGHT;
    
    font |= BOLD_MASK;
    
    font &= ~ITALIC_MASK;
    
    font |= UNDERLINE_MASK;
    
    show_font(&font);

    while((choice = get_choice()) && (choice != 'q')) {
        switch (choice) {
            case 'f':
                change_font(&font);
                show_font(&font);
                break;
            case 's':
                change_size(&font);
                show_font(&font);
                break;
            case 'a':
                change_alignment(&font);
                show_font(&font);
                break;
            case 'b':
                toggle_bold(&font);
                show_font(&font);
                break;
            case 'i':
                toggle_italic(&font);
                show_font(&font);
                break;
            case 'u':
                toggle_underline(&font);
                show_font(&font);
                break;
        }
    }
    puts("Bye.");
    return 0;
}

char get_choice()
{
    char choice;
    
    puts("f) change font  s) change size  a) change alignment");
    puts("b) toggle bold  i) toggle itatlic  u) toggle underline");
    puts("q) quit");
    
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

void change_font(unsigned long * pfont)
{
    int id;
    puts("Enter font id (0-255):");
    scanf("%d", &id);
    eat_line();
    set_font_id(pfont, id);
}

void change_size(unsigned long * pfont) {
    int size;
    puts("Enter font size (0-127):");
    scanf("%d", &size);
    eat_line();
    set_font_size(pfont, size);
}

void change_alignment(unsigned long * pfont)
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
            (*pfont) &= ~ALIGNMENT_MASK;
            (*pfont) |= ALIGNMENT_LEFT;
            break;
        case 'c':
            (*pfont) &= ~ALIGNMENT_MASK;
            (*pfont) |= ALIGNMENT_CENTER;
            break;
        case 'r':
            (*pfont) &= ~ALIGNMENT_MASK;
            (*pfont) |= ALIGNMENT_RIGHT;
            break;
    }
}

void toggle_bold(unsigned long * pfont)
{
    (*pfont) ^= BOLD_MASK;
}

void toggle_italic(unsigned long * pfont)
{
    (*pfont) ^= ITALIC_MASK;
}

void toggle_underline(unsigned long * pfont)
{
    (*pfont) ^= UNDERLINE_MASK;
}

void show_font(unsigned long * pfont)
{
    static char* alignments[3] = {
        "left",
        "center",
        "right"
    };
    
    puts("ID  SIZE  ALIGNMENT  B  I  U");
    printf("%lu  ", (*pfont) & ID_MASK);
    printf("%lu  ", ((*pfont) & SIZE_MASK) >> SIZE_OFFSET);
    printf("%s  ", alignments[(((*pfont) & ALIGNMENT_MASK) >> ALIGNMENT_OFFSET) - 1]);
    printf("%s  ", (((*pfont) & BOLD_MASK) >> BOLD_OFFSET) ? "on" : "off");
    printf("%s  ", (((*pfont) & ITALIC_MASK) >> ITALIC_OFFSET) ? "on" : "off");
    printf("%s  ", (((*pfont) & UNDERLINE_MASK) >> UNDERLINE_OFFSET) ? "on" : "off");
    putchar('\n');
}

void set_font_id(unsigned long * pfont, int id) {
    (*pfont) &= ~ID_MASK;
    (*pfont) |= (ID_MASK & id);
}

void set_font_size(unsigned long * pfont, int size) {
    (*pfont) &= ~SIZE_MASK;
    (*pfont) |= (SIZE_MASK & (size << SIZE_OFFSET));
}
