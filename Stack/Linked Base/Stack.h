//Stack - linked based "header file"

typedef char StackEntry;
typedef struct stacknode{
    struct stacknode *next;
    StackEntry entry;
}StackNode;

typedef struct stack{
    int size;
    struct stacknode *top;
}Stack;

void createStack(Stack*);
void clearStack(Stack*);

int stackSize(Stack*);
int stackFull(Stack*);
int stackEmpty(Stack*);

int push(StackEntry,Stack*);
void pop(StackEntry*,Stack*);
void stackTop(StackEntry*,Stack*);
void stackTraverse(Stack*,void (*pf)(StackEntry*));
