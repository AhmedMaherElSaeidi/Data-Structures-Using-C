//Stack - Array based "header file"

#define Max 20

typedef char StackEntry;
typedef struct stack{
    int top;
    StackEntry entry[Max];
}Stack;

void createStack(Stack*);
void clearStack(Stack*);

int stackSize(Stack*);
int stackFull(Stack*);
int stackEmpty(Stack*);

void push(StackEntry,Stack*);
void pop(StackEntry*,Stack*);
void stackTop(StackEntry*,Stack*);
void stackTraverse(Stack*,void (*pf)(StackEntry*));
