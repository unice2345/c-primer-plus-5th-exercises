#include <stdlib.h>
#include "list2.h"

void InitializeList(List * plist) {
    plist->head = NULL;
    plist->end = NULL;
}

bool ListIsEmpty(const List * plist) {
    return plist->head == NULL && plist->end == NULL;
}

bool ListIsFull(const List * plist) {
    Node * pt;
    bool full;
    
    pt = (Node*) malloc(sizeof(Node));
    if (pt == NULL) 
        full = true;
    else
        full = false;
    free(pt);
    return full;
}

unsigned int ListItemCount(const List * plist) {
    unsigned int count = 0;
    Node * current = plist->head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

bool AddItem(Item item, List * plist)
{    
    Node * current = plist->end;
    
    Node * pnode = (Node*)malloc(sizeof(Node));
    if (pnode != NULL) {
        pnode->item = item;
        pnode->next = NULL;
    } else {
        return false;
    }
    
    if (current == NULL) {
        plist->head = pnode;
        plist->end = pnode;
    } else {
        plist->end->next = pnode;
        plist->end = pnode;
    }
    return true;
}

void Traverse(const List * plist, void (*pfun)(Item item))
{
    Node * current = plist->head;
    
    while (current != NULL) {
        pfun(current->item);
        current = current->next;
    }
}

void EmptyList(List * plist) {
    
    Node * current = plist->head;
    Node * pnode;
    
    while (current != NULL) {
        pnode = current;
        current = current->next;
        free(pnode);
    }
    plist->head = NULL;
    plist->end = NULL;
}