#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void display(QueueEntry *pe){
    printf("%c\n", *pe);
}
int main()
{
    Queue q;
    createQueue(&q);

    char c = getchar();
    while(!queueFull(&q) && c != '\n'){
        if(!enQueue(c, &q)){
            return 1;
        }
        c = getchar();
    }

    queueFront(&c, &q);
    printf("Queue size is %d\n",queueSize(&q));
    printf("Queue front is %c\n",c);

//    while(!queueEmpty(&q)){
//        deQueue(&c, &q);
//        printf("%c\n",c);
//    }

    traverseQueue(&q, display);

    return 0;
}