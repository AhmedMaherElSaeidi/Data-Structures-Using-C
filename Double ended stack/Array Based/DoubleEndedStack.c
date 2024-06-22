#include "DoubleEndedStack.h"
// Double Ended Stack - Array based "C file"

void createDE(DEStack *ps){
    ps->down = -1;
    ps->top = MAX;
    ps->size = 0;
}
void clearDE(DEStack *ps){
    ps->down = -1;
    ps->top = MAX;
    ps->size = 0;
}

int DESize(DEStack *ps){
    return ps->size;
}
int DEFull(DEStack *ps){
    //return ps->size == MAX;
    return ps->down == ps->top - 1;
}
int DEEmpty_down(DEStack *ps){
    return ps->down == -1;
}
int DEEmpty_top(DEStack *ps){
    return ps->top == MAX;
}

void DEPush_down(DEStack *ps,DESType e){
    ps->entry[++ps->down] = e;
    ps->size++;
}
void DEPush_top(DEStack *ps,DESType e){
    ps->entry[--ps->top] = e;
    ps->size++;
}
void DEPop_down(DEStack *ps,DESType *pe){
    *pe = ps->entry[ps->down--];
    ps->size--;
}
void DEPop_top(DEStack *ps,DESType *pe){
    *pe = ps->entry[ps->top++];
    ps->size--;
}
void DERetrieve_down(DEStack *ps,DESType *pe){
    *pe = ps->entry[ps->down];
}
void DERetrieve_top(DEStack *ps,DESType *pe){
    *pe = ps->entry[ps->top];
}

void DETraverse_down(DEStack *ps,void (*pf)(DESType*)){
    for(int count = ps->down ; count > -1 ; count--)
        (*pf)(&ps->entry[count]);
}
void DETraverse_top(DEStack *ps,void (*pf)(DESType*)){
    for(int count = ps->top ; count < MAX ; count++)
        (*pf)(&ps->entry[count]);
}
