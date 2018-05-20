#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void InitializeQueue(Queue * pq) {
    pq->front = NULL;
    pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsFull(const Queue * pq) {
    return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue * pq) {
    return pq->items == 0;
}

int QueueItemCount(const Queue * pq) {
    return pq->items;
}

bool Enqueue(Item item, Queue * pq) {
    Node * pnode;
    if (QueueIsFull(pq)) 
        return false;

    pnode = (Node*)malloc(sizeof(Node));
    if (pnode == NULL) {
        fprintf(stderr, "Unable to alloc memeory");
        return false;
    }
    pnode->item = item;
    pnode->next = NULL;
    
    if (QueueIsEmpty(pq)) {
        pq->front = pq->rear = pnode;
        pq->front->next = pq->rear;
    } else {
        pq->rear->next = pnode;
        pq->rear = pnode;
    }
    
    pq->items++;
    
    return true;
}

bool DeQueue(Item * pitem, Queue * pq) {
    Node * pnode;
    if (QueueIsEmpty(pq)) 
        return false;
        
    *pitem = pq->front->item;
    pnode = pq->front;
    pq->front = pq->front->next;
    free(pnode);
    pq->items--;
    
    if (pq->items == 0)
        pq->rear = NULL;
    return true;
}

void EmptyQueue(Queue * pq) {
    Item item;
    while (!QueueIsEmpty(pq)) {
        DeQueue(&item, pq);
    }
}