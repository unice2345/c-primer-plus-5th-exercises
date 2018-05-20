#ifndef STACK_H_
#define STACK_H_
#include <stdbool.h>
#define MAXSIZE 100
typedef char Item;
typedef struct stack {
    Item items[MAXSIZE];
    int top;
} Stack;

void InitializeStack(Stack * ps);

bool FullStack(const Stack * ps);

bool EmptyStack(const Stack * ps);

bool Push(Item item, Stack * ps);

bool Pop(Item * item, Stack * ps);

#endif