/* pe17-1.c -- 双向链表 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45
struct film {
    char title[TSIZE];
    int rating;
    struct film * next;
    struct film * prev;
};

void show_moview(struct film* current);

int main(void)
{
    struct film *head = NULL;
    struct film *prev, *current;
    char input[TSIZE];
    
    puts("Enter first movie title:");
    while (gets(input) != NULL && input[0] != '\0') {
        current = (struct film*) malloc(sizeof(struct film));
        if (head == NULL)
            head = current;
        else
            prev->next = current;
        current->next = NULL;
        current->prev = prev;

        strcpy(current->title, input);
        puts("Enter your rating<0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop): ");
            
        prev = current;
    }
    head->prev = current;
    
    // show
    if (head == NULL)
        printf("No data entered.");
    else
        printf("Movie list: \n");
        
     // 顺序显示   
//    current = head;
//    while (current != NULL) {
//        printf("Movie: %s; Rating: %d\n", current->title, current->rating);
//        current = current->next;
//    }

    // 逆序显示
//    current = head->prev;
//    while (current != head) {
//        printf("Movie: %s; Rating: %d\n", current->title, current->rating);
//        current = current->prev;
//    }
//    printf("Movie: %s; Rating: %d\n", current->title, current->rating);

    // 递归逆序显示
    show_moview(head);
    
    // free buffer
    current = head;
    while (current != NULL) {
        prev = current;
        current = current->next;
        free(prev);
    }
    
    printf("Bye.\n");
    return 0;
}

void show_moview(struct film* current) {  
    if (current != NULL) {
        show_moview(current->next);
        printf("Movie: %s; Rating: %d\n", current->title, current->rating);
    } else {
        return;
    }
}