/* pe17-5.c -- 使用栈 */
#include <stdio.h>
#include <string.h>
#include "stack.h"
int main(void) 
{
    Item msg[] = "hello, world!";
    int i;
    Stack stack;
    Item item;
    int length = strlen(msg);
    
    InitializeStack(&stack);
    for (i = 0; i < length; i++)
        Push(msg[i], &stack);
        
    while (!EmptyStack(&stack)) {
        Pop(&item, &stack);
        putchar(item);
    }
    printf("\n---------------------------------------------\n");
    return 0;
}