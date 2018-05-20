#include <stdlib.h>
#include "list.h"

void InitializeList(List * plist) {
    *plist = NULL;
}

bool ListIsEmpty(const List * plist) {
    return *plist == NULL;
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
    Node * current = *plist;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

bool AddItem(Item item, List * plist)
{    
    Node * current = *plist;
    
    Node * pnode = (Node*)malloc(sizeof(Node));
    if (pnode != NULL) {
        pnode->item = item;
        pnode->next = NULL;
    } else {
        return false;
    }
    
    if (current == NULL) {
        *plist = pnode;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = pnode;
    }
    return true;
}

void Traverse(const List * plist, void (*pfun)(Item item))
{
    Node * current = *plist;
    
    while (current != NULL) {
        pfun(current->item);
        current = current->next;
    }
}

void EmptyList(List * plist) {
    
    Node * current = *plist;
    Node * pnode;
    
    while (current != NULL) {
        pnode = current;
        current = current->next;
        free(pnode);
    }
    *plist = NULL;
}