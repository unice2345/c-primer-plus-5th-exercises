/* manybook.c -- multiple book inventory */
#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 /* maximum number of books */
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void sort_by_title(struct book *books[],  int count);
void sort_by_value(struct book *books[],  int count);

int main(void)
{
    struct book library[MAXBKS];
    struct book *books[MAXBKS];
    struct book *books_value[MAXBKS];
    int count  = 0;
    int index;
    
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && gets(library[count].title) != NULL && library[count].title[0] != '\0') {
        // 获取结构的指针
        books[count] = &library[count];
        books_value[count] = &library[count];
        
        printf("Now enter the author:");
        gets(library[count].author);
        printf("Now enter the value:");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            printf("Enter the next title:");
    }
    
    if (count > 0) {
        printf("List of books:\n");
        for (index = 0; index < count; index++) {
            printf("%s by %s, $%.2f\n", library[index].title, library[index].author, library[index].value);
        }
        
        sort_by_title(books, count);
        printf("List of books, sort by title:\n");
        for (index = 0; index < count; index++) {
            printf("%s by %s, $%.2f\n", books[index]->title, books[index]->author, books[index]->value);
        }
        
        sort_by_value(books_value, count);
        printf("List of books, sort by value:\n");
        for (index = 0; index < count; index++) {
            printf("%s by %s, $%.2f\n", books_value[index]->title, books_value[index]->author, books_value[index]->value);
        }
    } else {
        printf("No book? Too bad.\n");
    }
    
    return 0;
}

void sort_by_title(struct book *books[],  int count)
{
    struct book *tmp;
    int i, j;
    
    for (i = count-2; i >= 0; i--) {
        for (j = 0; j <= i; j++) {
            if (strcmp(books[j]->title, books[j+1]->title) > 0) {
                tmp = books[j];
                books[j] = books[j+1];
                books[j+1] = tmp;
            }
        }
    }
}

void sort_by_value(struct book *books[],  int count)
{
    struct book *tmp;
    int i, j;
    
    for (i = 1; i < count; i++) {
        for (j = 0; j < count-i; j++) {
            if (books[j]->value > books[j+1]->value) {
                tmp = books[j];
                books[j] = books[j+1];
                books[j+1] = tmp;
            }
        }
    }
}