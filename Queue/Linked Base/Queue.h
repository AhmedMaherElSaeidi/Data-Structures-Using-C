// Queue - linked based "header file"

typedef char QueueEntry;
typedef struct queuenode{
    struct queuenode *next;
    QueueEntry entry;
}QueueNode;
typedef struct queue{
    int size;
    struct queuenode *front;
    struct queuenode *rear;
}Queue;

void createQueue(Queue*);
void clearQueue(Queue*);

int queueSize(Queue*);
int queueEmpty(Queue*);
int queueFull(Queue*);

int enQueue(QueueEntry, Queue*);
void deQueue(QueueEntry*, Queue*);
void queueFront(QueueEntry*, Queue*);
void traverseQueue(Queue*,void (*pf)(QueueEntry*));
