//Stack - linked based  "C file"
#include "Stack.h"
#include <stdlib.h>

void createStack(Stack *ps){
    ps->top = NULL;
    ps->size = 0;
}
void clearStack(Stack *ps){
    StackNode *pn = ps->top;
    while(pn){
        pn = pn->next;
        free(ps->top);
        ps->top = pn;
    }

    ps->size = 0;
}

int stackSize(Stack *ps){
    return ps->size;
}
int stackFull(Stack *ps){
    return 0;
}
int stackEmpty(Stack *ps){
    return !ps->top;
}

int push(StackEntry e,Stack *ps){
    StackNode *pn;
    if(pn = (StackNode*)malloc(sizeof(StackNode))){
        pn->entry = e;
        pn->next = ps->top;
        ps->top = pn;
        ps->size++;
        return 1;
    }
    return 0;
}
void pop(StackEntry *pe,Stack *ps){
    StackNode *pn = ps->top;
    *pe = pn->entry;
    ps->top = pn->next;
    free(pn);
    ps->size--;
}
void stackTop(StackEntry *pe,Stack *ps){
    *pe = ps->top->entry;
}
void stackTraverse(Stack *ps,void (*pf)(StackEntry*)){
    for(StackNode *pn = ps->top; pn ; pn = pn->next)
        (*pf)(&pn->entry);
}
