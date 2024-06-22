#include "DoubleEndedStack.h"
#include <stdlib.h>
// Double Ended Stack - Linked based "C file"

void createDE(DEStack *ps){
    ps->size = 0;
    ps->down = NULL;
    ps->top = NULL;
}
void clearDE(DEStack *ps){
    DESNode *pn;

    pn = ps->down;
    while(ps->down){
        pn = pn->next;
        free(ps->down);
        ps->down = pn;
    }

    pn = ps->top;
    while(ps->top){
        pn = pn->next;
        free(ps->top);
        ps->top = pn;
    }

    ps->size = 0;
}

int DESize(DEStack *ps){
    return ps->size;
}
int DEFull(DEStack *ps){
    return 0;
}
int DEEmpty_down(DEStack *ps){
    return !ps->down;
}
int DEEmpty_top(DEStack *ps){
    return !ps->top;
}

int DEPush_down(DEStack *ps,DESType e){
    DESNode *pn;
    if(pn = (DESNode*)malloc(sizeof(DESNode))){
        pn->entry = e;
        pn->next = ps->down;
        ps->down = pn;
        ps->size++;
        return 1;
    }
    return 0;
}
int DEPush_top(DEStack *ps,DESType e){
    DESNode *pn;
    if(pn = (DESNode*)malloc(sizeof(DESNode))){
        pn->entry = e;
        pn->next = ps->top;
        ps->top = pn;
        ps->size++;
        return 1;
    }
    return 0;
}
void DEPop_down(DEStack *ps,DESType *pe){
    DESNode *tmp = ps->down;
    *pe = tmp->entry;
    ps->down = tmp->next;
    free(tmp);
    ps->size--;
}
void DEPop_top(DEStack *ps,DESType *pe){
   DESNode *tmp = ps->top;
    *pe = tmp->entry;
    ps->top = tmp->next;
    free(tmp);
    ps->size--;
}
void DERetrieve_down(DEStack *ps,DESType *pe){
    *pe = ps->down->entry;
}
void DERetrieve_top(DEStack *ps,DESType *pe){
    *pe = ps->top->entry;
}

void DETraverse_down(DEStack *ps,void (*pf)(DESType*)){
    for(DESNode *pn = ps->down; pn ; pn = pn->next)
        (*pf)(&pn->entry);
}
void DETraverse_top(DEStack *ps,void (*pf)(DESType*)){
    for(DESNode *pn = ps->top; pn ; pn = pn->next)
        (*pf)(&pn->entry);
}
