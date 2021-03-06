#ifndef TREE_H_
#define TREE_H_
#include <stdbool.h>

typedef struct item {
    char petname[20];
    char petkind[20];
} Item;

#define MAXITEMS 10

typedef struct node {
    Item item;
    struct node * left;
    struct node * right;
} Node;

typedef struct tree {
    Node * root;
    int size;
} Tree;

void InitializeTree(Tree * ptree);

bool TreeIsEmpty(const Tree * ptree);

bool TreeIsFull(const Tree * ptree);

int TreeItemCount(const Tree * ptree);

bool AddItem(const Item * pitem, Tree * ptree);

bool InTree(const Item * pitem, const Tree * ptree);

bool DeleteItem(const Item * pitem, Tree * ptree);

void Traverse(const Tree * ptree, void (*pfun)(Item item));

void DeleteAll(Tree * ptree);
#endif