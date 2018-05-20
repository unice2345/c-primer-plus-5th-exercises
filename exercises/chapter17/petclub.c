#include <stdio.h>
#include <string.h>
#include "tree.h"

void addpet(Tree * ptree);
void droppet(Tree * ptree);
void findpet(Tree * ptree);
void showpets(const Tree * ptree);
void printItem(Item item);
char menu(void);

int main(void) 
{
    Tree pets;
    char choice;
    
    InitializeTree(&pets);
    while ((choice = menu()) != 'q') {
        switch (choice) {
            case 'a': addpet(&pets); break;
            case 'l': showpets(&pets); break;
            case 'f': findpet(&pets); break;
            case 'n': printf("%d pets in the club\n", TreeItemCount(&pets)); break;
            case 'd': droppet(&pets); break;
            default: puts("switch error");
        }
    }
    
    DeleteAll(&pets);
    puts("Bye.");

    
    printf("\n---------------------------------------------\n");
    return 0;
}

void addpet(Tree * ptree) {
    Item item;
    
    if (TreeIsFull(ptree)) 
        puts("No room in the club");
    else {
        puts("Please enter name of pet:");
        gets(item.petname);
        puts("Please enter pet kind:");
        gets(item.petkind);
        //
        AddItem(&item, ptree);
    }
}


void showpets(const Tree * ptree) {
    if (TreeIsEmpty(ptree))
        puts("No entries!");
    else
        Traverse(ptree, printItem);
}


void printItem(Item item) {
    printf("Pet: %-19s Kind: %-19s\n", item.petname, item.petkind);
}

void droppet(Tree * ptree) {
    Item item;
    
    if (TreeIsEmpty(ptree)) {
        puts("No entries");
        return;
    }
    
    puts("Please enter name of pet:");
    gets(item.petname);
    puts("Please enter pet kind:");
    gets(item.petkind);
    printf("%s the %s ", item.petname, item.petkind);
    if (DeleteItem(&item, ptree))
        printf("is dropped from the club.\n");
    else
        printf("is not a member.\n");
}

void findpet(Tree * ptree) {
    Item item;
    
    if (TreeIsEmpty(ptree)) {
        puts("No entries");
        return;
    }
    
    puts("Please enter name of pet:");
    gets(item.petname);
    puts("Please enter pet kind:");
    gets(item.petkind);
    printf("%s the %s ", item.petname, item.petkind);
    if (InTree(&item, ptree))
        printf("is a member.\n");
    else
        printf("is not a member.\n");
}

char menu(void) {
    int ch;
    
    puts("-------------Pet Club--------------");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add pet           1) show list of pets");
    puts("n) number of pets    f) find pets");
    puts("d) delete a pet      q) quit");
    while ((ch = getchar()) != EOF) {
        while (getchar() != '\n')
            continue;
        if (strchr("alnfdq", ch) == NULL)
            puts("Please enter a, l, n, f, d or q:");
        else
            break;
    }
    
    return ch;
}