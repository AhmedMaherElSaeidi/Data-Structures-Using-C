#include <stdlib.h>
#include "List.h"
// List - List based "c file"

void createList(List *pl){
    pl->head = NULL;
    pl->size = 0;
}
void clearList(List *pl){
    ListNode *pn = pl->head;
    while(pl->head){
        pn = pn->next;
        free(pl->head);
        pl->head = pn;
    }
    pl->size = 0;
}

int listSize(List *pl){
    return pl->size;
}
int listEmpty(List *pl){
    return !pl->size;
}
int listFull(List *pl){
    return 0;
}

int insertList(ListEntry e, int pos, List *pl){
    ListNode *pn;
    if(pn = (ListNode*)malloc(sizeof(ListNode))){
        pn->entry = e;
        if(pos == 0){
            pn->next = pl->head;
            pl->head = pn;
        }else{
            ListNode *tmp = pl->head;
            for(int count = 0 ; count < pos - 1 ; count++)
                tmp = tmp->next;
            pn->next = tmp->next;
            tmp->next = pn;
        }
        pl->size++;
        return 1;
    }
    return 0;
}
void replaceList(ListEntry e, int pos, List *pl){
    ListNode *pn = pl->head;
    for(int count = 0 ; count < pos ; count++)
        pn = pn->next;
    pn->entry = e;
}
void deleteList(ListEntry *pe, int pos, List *pl){
    ListNode *tmp = pl->head;
    if(pos == 0){
        *pe = pl->head->entry;
        pl->head = pl->head->next;
        free(tmp);
    }else{
        ListNode *ptmp;
        for(int count = 0 ; count < pos - 1 ; count++)
            tmp = tmp->next;
        ptmp = tmp->next;
        *pe = ptmp->entry;
        tmp->next = tmp->next->next;
        free(ptmp);
       }
    pl->size--;
}
void retrieveList(ListEntry *pe, int pos, List *pl){
    ListNode *pn = pl->head;
    for(int count = 0 ; count < pos ; count++)
        pn = pn->next;
    *pe = pn->entry;
}
void traverseList(List *pl,void (*pf)(ListEntry*)){
    for(ListNode *pn = pl->head ; pn ; pn = pn->next)
        (*pf)(&pn->entry);

}
