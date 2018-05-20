#include "stack.h"

void InitializeStack(Stack * ps) {
    ps->top = -1;
}

bool FullStack(const Stack * ps) {
    return ps->top == MAXSIZE;
}

bool EmptyStack(const Stack * ps) {
    return ps->top < 0;
}

bool Push(Item item, Stack * ps) {
    if (FullStack(ps))
        return false;
        
    ps->items[++(ps->top)] = item;
    return true;
}

bool Pop(Item * item, Stack * ps) {
    if (EmptyStack(ps))
        return false;
    
    *item = ps->items[(ps->top)--];
    return true;
}