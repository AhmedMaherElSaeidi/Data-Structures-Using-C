#include "Queue.h"
// Queue - Array based "c file"

void createQueue(Queue *pq){
    pq->size = 0;
    pq->front = 0;
    pq->rear = -1;
}
void clearQueue(Queue *pq){
    pq->size = 0;
    pq->front = 0;
    pq->rear = -1;
}

int queueSize(Queue *pq){
    return pq->size;
}
int queueEmpty(Queue *pq){
    return !pq->size;
}
int queueFull(Queue *pq){
    return pq->size == MAX;
}

void enQueue(QueueEntry e, Queue *pq){
    pq->rear = ( pq->rear + 1) % MAX;
    pq->entry[pq->rear] = e;
    pq->size++;
}
void deQueue(QueueEntry *pe, Queue *pq){
    *pe = pq->entry[pq->front];
    pq->front = ( pq->front + 1) % MAX;
    pq->size--;
}
void queueFront(QueueEntry *pe, Queue *pq){
    *pe = pq->entry[pq->front];
}
void traverseQueue(Queue *pq,void (*pf)(QueueEntry*)){
    for (int pos = pq->front; pos != ( pq->rear + 1 ) % MAX ; pos = ( pos + 1 ) % MAX)
        (*pf)(&pq->entry[pos]);
}
