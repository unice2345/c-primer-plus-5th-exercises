#include <stdlib.h>
#include "list3.h"

void InitializeList(List * plist) {
    plist->items = 0;
}

bool ListIsEmpty(const List * plist) {
    return plist->items == 0;
}

bool ListIsFull(const List * plist) {
    return plist->items == MAXSIZE;
}

unsigned int ListItemCount(const List * plist) {
    return plist->items;
}

bool AddItem(Item item, List * plist)
{    
    if (ListIsFull(plist))
        return false;
    
    plist->entries[plist->items++] = item;
    return true;
}

void Traverse(const List * plist, void (*pfun)(Item item))
{
    int i;
    for (i = 0; i < plist->items; i++) {
        pfun(plist->entries[i]);
    }
}

void EmptyList(List * plist) {
    plist->items = 0;
}