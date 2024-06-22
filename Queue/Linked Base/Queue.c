#include "Queue.h"
#include <stdlib.h>
// Queue - linked based "c file"

void createQueue(Queue *pq){
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}
void clearQueue(Queue *pq){
    while(pq->front){
        pq->rear = pq->front->next;
        free(pq->front);
        pq->front = pq->rear;
    }
    pq->size = 0;
}

int queueSize(Queue *pq){
    return pq->size;
}
int queueEmpty(Queue *pq){
    return !pq->front;
}
int queueFull(Queue *pq){
    return 0;
}

int enQueue(QueueEntry e, Queue *pq){
    QueueNode *pn;
    if(pn = (QueueNode*)malloc(sizeof(QueueNode))){
        pn->entry = e;
        pn->next = NULL;

        if(!pq->front){
            pq->front = pn;
        }else{
            pq->rear->next = pn;
        }

        pq->rear = pn;
        pq->size ++;
        return 1;
    }
    return 0;
}
void deQueue(QueueEntry *pe, Queue *pq){
    QueueNode *pn = pq->front;
    *pe = pn->entry;
    pq->front = pn->next;
    free(pn);
    if(!pq->front){
        pq->rear = NULL;
    }
    pq->size--;
}
void queueFront(QueueEntry *pe, Queue *pq){
    *pe = pq->front->entry;
}
void traverseQueue(Queue *pq,void (*pf)(QueueEntry*)){
    for (QueueNode *pn = pq->front ; pn ; pn = pn->next )
        (*pf)(&pn->entry);
}
