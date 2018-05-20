#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree3.h"

void findwords(Tree * ptree);
void showwords(const Tree * ptree);
void printItem(const Item * pitem);
char menu(void);
Item * makeItem();

/**
 * @brief 将文件中的单词及个数存入二叉树
 * @param filename 文件名字
 * @param ptree 二叉树
 */
bool storeWordsToTree(const char* filename, Tree * ptree);

int main(void) 
{
    Tree words_counter;
    char choice;
    
    InitializeTree(&words_counter);
    
    storeWordsToTree("test.txt", &words_counter);
    
    while ((choice = menu()) != 'q') {
        switch (choice) {
            case 'l': showwords(&words_counter); break;
            case 'f': findwords(&words_counter); break;
            default: puts("switch error");
        }
    }
    
    DeleteAll(&words_counter);
    puts("Bye.");

    
    printf("\n---------------------------------------------\n");
    return 0;
}

void showwords(const Tree * ptree) {
    if (TreeIsEmpty(ptree))
        puts("No entries!");
    else
        Traverse(ptree, printItem);
}


void printItem(const Item * pitem) {
    printf("words: %-19s count: %-19d\n", pitem->words, pitem->count);
}

void findwords(Tree * ptree) {
    Item * pitem = makeItem();
    
    if (TreeIsEmpty(ptree)) {
        puts("No entries");
        return;
    }
    
    puts("Please enter words:");
    gets(pitem->words);
    printf("%s ", pitem->words);
    
    Node * pnode = findNode(pitem, ptree);
    if (pnode != NULL)
        printf(" count is %d.\n", pnode->pitem->count);
    else
        printf("is not a member.\n");
}

char menu(void) {
    int ch;
    
    puts("-------------Words Counter--------------");
    puts("Enter the letter corresponding to your choice:");
    puts("1) show list of words");
    puts("f) find words");
    puts("q) quit");
    while ((ch = getchar()) != EOF) {
        while (getchar() != '\n')
            continue;
        if (strchr("lfq", ch) == NULL)
            puts("Please enter l, f or q:");
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
    pitem->count = 1;
    
    return pitem;
}

bool storeWordsToTree(const char* filename, Tree * ptree) {
    char words[64];
    // 打开文件
    FILE * pfile = fopen(filename, "r");
    if (pfile == NULL) {
        fprintf(stderr, "Cannot open file %s\n", filename);
        return false;
    }
    
    // 读取单词
    while (fscanf(pfile, "%s", words) > 0) {
        Item * pitem = makeItem();
        strcpy(pitem->words, words);
        AddItem(pitem, ptree);
    }
    
    // 关闭文件
    fclose(pfile);
    
    return true;
}