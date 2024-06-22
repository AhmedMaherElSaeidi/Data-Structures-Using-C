#define MAX 20
// Queue - Array based "header file"

typedef char QueueEntry;
typedef struct queue{
    int size;
    int front;
    int rear;
    QueueEntry entry[MAX];
}Queue;

void createQueue(Queue*);
void clearQueue(Queue*);

int queueSize(Queue*);
int queueEmpty(Queue*);
int queueFull(Queue*);

void enQueue(QueueEntry, Queue*);
void deQueue(QueueEntry*, Queue*);
void queueFront(QueueEntry*, Queue*);
void traverseQueue(Queue*,void (*pf)(QueueEntry*));
