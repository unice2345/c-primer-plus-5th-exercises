#ifndef TREE_H_
#define TREE_H_
#include <stdbool.h>

typedef struct item {
    char words[20];
    int count;
} Item;

#define MAXITEMS 10

typedef struct node {
    Item * pitem;
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

bool AddItem(Item * pitem, Tree * ptree);

bool InTree(const Item * pitem, const Tree * ptree);

bool DeleteItem(const Item * pitem, Tree * ptree);

void Traverse(const Tree * ptree, void (*pfun)(const Item * pitem));

void DeleteAll(Tree * ptree);

Node * findNode(const Item * pitem, const Tree * ptree);
#endif