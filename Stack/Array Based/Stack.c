//Stack - Array based  "C file"
#include "Stack.h"

void createStack(Stack *ps){
    ps->top = -1;
}
void clearStack(Stack *ps){
    ps->top = -1;
}

int stackSize(Stack *ps){
    return ( ps->top + 1 );
}
int stackFull(Stack *ps){
    return ps->top == Max - 1;
}
int stackEmpty(Stack *ps){
    return ps->top == -1;
}

void push(StackEntry e,Stack *ps){
    ps->entry[++ps->top] = e;
}
void pop(StackEntry *e,Stack *ps){
    *e = ps->entry[ps->top--];
}
void stackTop(StackEntry *e,Stack *ps){
    *e = ps->entry[ps->top];
}
void stackTraverse(Stack *ps,void (*pf)(StackEntry*)){
    for(int i = ps->top ; i > -1 ; i--)
        (*pf)(&ps->entry[i]);
}
