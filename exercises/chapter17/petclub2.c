#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree2.h"
static int item_count;
static int total_item_count;
void addpet(Tree * ptree);
void droppet(Tree * ptree);
void findpet(Tree * ptree);
void showpets(const Tree * ptree);
void printItem(const Item * pitem);
void getItemCount(const Item * pitem);
char menu(void);
Item * makeItem();

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
            case 'n': //printf("%d pets in the club\n", TreeItemCount(&pets)); break;
                total_item_count = 0;
                Traverse(&pets, getItemCount);
                printf("%d pets in the club\n", total_item_count);
                break;
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
    Item * pitem = makeItem();
    
    if (TreeIsFull(ptree)) 
        puts("No room in the club");
    else {
        puts("Please enter name of pet:");
        gets(pitem->petname);
        puts("Please enter pet kind:");
        gets(pitem->petkind);
        //
        AddItem(pitem, ptree);
    }
}


void showpets(const Tree * ptree) {
    if (TreeIsEmpty(ptree))
        puts("No entries!");
    else
        Traverse(ptree, printItem);
}


void printItem(const Item * pitem) {
    while (pitem != NULL) {
        printf("Pet: %-19s Kind: %-19s\n", pitem->petname, pitem->petkind);
        pitem = pitem->next;
    }
}

void getItemCount(const Item * pitem) {
    item_count = 0;
    while (pitem != NULL) {
        item_count++;
        pitem = pitem->next;
    }
    total_item_count += item_count;
}

void droppet(Tree * ptree) {
    Item * pitem = makeItem();
    
    if (TreeIsEmpty(ptree)) {
        puts("No entries");
        return;
    }
    
    puts("Please enter name of pet:");
    gets(pitem->petname);
    puts("Please enter pet kind:");
    gets(pitem->petkind);
    printf("%s the %s ", pitem->petname, pitem->petkind);
    if (DeleteItem(pitem, ptree))
        printf("is dropped from the club.\n");
    else
        printf("is not a member.\n");
}

void findpet(Tree * ptree) {
    Item * pitem = makeItem();
    
    if (TreeIsEmpty(ptree)) {
        puts("No entries");
        return;
    }
    
    puts("Please enter name of pet:");
    gets(pitem->petname);
    puts("Please enter pet kind:");
    gets(pitem->petkind);
    printf("%s the %s ", pitem->petname, pitem->petkind);
    if (InTree(pitem, ptree))
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

Item * makeItem() {
    Item * pitem = (Item *) malloc(sizeof(Item));
    if (pitem == NULL) {
        fprintf(stderr, "Alloc memory failed. Abort the application.\n");
        exit(1);
    }
    pitem->next = NULL;
    
    return pitem;
}