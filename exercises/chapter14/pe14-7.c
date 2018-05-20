/* booksave.c -- 把结构内容保存到文件中 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10 /* maximum number of books */
struct book { /* set up book template */
 char title[MAXTITL];
 char author[MAXAUTL];
 float value;
};

char show_menu(void);
void show_libraray(struct book library[], int n);
void write_libraray_to_file(struct book library[], int count, FILE* pbook);

int main(void)
{
    struct book library[MAXBKS]; /* array of structures */
    
     int count = 0;
     int index, filecount;
     FILE * pbooks;
     int size = sizeof (struct book);
     char choice;
     int remove_index;
     int edit_index;
     
     if ((pbooks = fopen("book.dat", "r+b")) == NULL) {
        fprintf(stderr, "Cannot open file.");
        exit(1);
    }
    
    rewind(pbooks);
    
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
        if (count == 0)
            puts("Current contends of book.dat: ");
        printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
        count++;
    }
    
    // show menu
    choice = show_menu();
    printf("Your choice is %c\n", choice);
    
    // remove item
    if (choice == 'r') {
        puts("Which record dou you want to remove:");
        scanf("%d", &remove_index);
        for (index = remove_index; index < count-1; index++) {
            library[index] = library[index+1];
        }
        count--;
        
        //show_libraray(library, count);
        fclose(pbooks);
        if ((pbooks = fopen("book.dat", "w+b")) == NULL) {
            fprintf(stderr, "Cannot open file.");
            exit(1);
        }
        write_libraray_to_file(library, count, pbooks);
        fclose(pbooks);
    }
    
    // edit item
    if (choice == 'e') {
        puts("Which record dou you want to edit:");
        scanf("%d", &edit_index);
        while (getchar() != '\n')
            continue;
        puts("Enter new title:");
        gets(library[edit_index].title);
        puts("Now enter the author:");
        gets(library[edit_index].author);
        puts("Now enter the value:");
        scanf("%f", &library[edit_index++].value);
        while (getchar() != '\n')
            continue;
            
        puts("Here is the list of your books:\n");
        for (index = 0; index < count; index++) {
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        }
            
//        if (fseek(pbooks, (edit_index) * sizeof(struct book) * 1L, SEEK_SET) != 0) { // TODO ??? 结果错误
//            if (ferror(pbooks)) {
//                perror("fseek()");
//                exit(2);
//            }
//        }
//        fwrite(library + edit_index, size, 1, pbooks);
//        
        if ((pbooks = fopen("book.dat", "w+b")) == NULL) {
            fprintf(stderr, "Cannot open file.");
            exit(1);
        }
        write_libraray_to_file(library, count, pbooks);
        fclose(pbooks);
    }
    
    // append item
    if (choice == 'a') {
        filecount = count;
        if (count == MAXBKS) {
            fputs("The book.dat is full.\n", stderr);
            exit(2);
        }
        
        puts("Please add new book titles.");
        puts("Press [enter] at the start of a line to stop.");
        while (count < MAXBKS && gets(library[count].title) != NULL && library[count].title[0] != '\0') {
            puts("Now enter the author:");
            gets(library[count].author);
            puts("Now enter the value:");
            scanf("%f", &library[count++].value);
            while (getchar() != '\n')
                continue;
            if (count < MAXBKS)
                puts("Enter the next title:");
        }
        
        if (count > 0) {
            puts("Here is the list of your books:\n");
            for (index = 0; index < count; index++) {
                printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
            }
            fwrite(&library[filecount], size, count - filecount, pbooks);
        } else 
            puts("No books? Too bad.\n");
            
        puts("Bye.\n");
        fclose(pbooks);
    }
    return 0;
}

char show_menu(void)
{
    char choice;
    
    puts("Enter choice:");
    puts("a) append               e) edit");
    puts("r) remove               q) quit");
    
    choice = getchar();
    while (getchar() != '\n')
        continue;
    
    while (strchr("aerq", choice) == NULL) {
        puts("Enter a, e, r or q:");
     
        choice = getchar();
        while (getchar() != '\n')
            continue;   
    }
    return choice;
}

void show_libraray(struct book library[], int count) {
    int index;
    puts("Here is the list of your books:\n");
    for (index = 0; index < count; index++) {
        printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
    }
}

void write_libraray_to_file(struct book library[], int count, FILE* pbook)
{
    int index;
    
    if (count > 0) {
        puts("Here is the list of your books:\n");
        for (index = 0; index < count; index++) {
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        }
        //rewind(pbook);
        fwrite(&library[0], sizeof(struct book), count, pbook);
    } else 
        puts("No books? Too bad.\n");
}