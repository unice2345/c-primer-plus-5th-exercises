#include <stdio.h>
#include <stdlib.h>
#include "list3.h"
void show_movies(Item item);
int main(void)
{
    List movies;
    Item temp;
    
    // 初始化
    InitializeList(&movies);
    if (ListIsFull(&movies)) {
        fprintf(stderr, "No memory available!\n");
        exit(1);
    }
    
    // 收集并存储
    puts("Enter first movie title");
    while (gets(temp.title) != NULL && temp.title[0] != '\0') {
        puts("Enter your rating<0-10>: ");
        scanf("%d", &temp.rating);
        while (getchar() != '\n')
            continue;
            
        if (!AddItem(temp, &movies)) {
            fprintf(stderr, "Add item failed.\n");
            break;
        }
        if (ListIsFull(&movies)) {
            printf("The list is full\n");
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }
     
    // 显示
    if (ListIsEmpty(&movies)) 
        printf("No data entered.\n");
    else 
        Traverse(&movies, show_movies);
    printf("You have entered %d movies.\n", ListItemCount(&movies));
    
    return 0;
}

void show_movies(Item item)
{
    printf("Movie: %s; Rating: %d\n", item.title, item.rating);
}