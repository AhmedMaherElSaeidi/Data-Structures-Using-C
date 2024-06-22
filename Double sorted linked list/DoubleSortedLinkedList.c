#include "DoubleSortedLinkedList.h"
#include <stdlib.h>

void createList(List *pl){
    pl->size = 0;
    pl->position = -1;
    pl->head = NULL;
    pl->current = NULL;
}
void clearList(List *pl){
    pl->current = pl->head;
    while(pl->current){
        pl->head = pl->head->next;
        free(pl->current);
        pl->current = pl->head;
    }
    pl->position = -1;
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

int insertList(ListEntry e, List *pl){
    ListNode *pn;
    int i = 0;
    if(pn = (ListNode*)malloc(sizeof(ListNode))){
        pn->entry = e;
        if(!pl->head){
            pl->head = pn;
            pl->current = pn;
            pl->position = 0;
            pn->next = NULL;
            pn->previous = NULL;
        }else{
            if(e.key >= pl->current->entry.key){
                while(pl->current->entry.key < e.key){
                    if(!pl->current->next)
                        break;
                    pl->current = pl->current->next;
                    pl->position++;
                }
            }else{
               while(pl->current->entry.key > e.key){
                    pl->current = pl->current->previous;
                    pl->position--;
                    if(!pl->current)
                        break;
                }
            }
            if(!pl->current){
                pn->next = pl->head;
                pn->previous = pl->head->previous;
                pl->head->previous = pn;
                pl->head = pn;
                pl->current = pn;
                pl->position++;
            }else{
                pn->next = pl->current->next;
                pn->previous = pl->current;
                if(pl->current->next)
                    pl->current->next->previous = pn;
                pl->current->next = pn;
            }
        }
        pl->size++;
        return 1;
    }
    return 0;
}
void deleteList(ListEntry *pe, List *pl){
    ListNode *tmp = pl->head;
    if(pl->size == 1){
        pl->head = tmp->next;
        pl->current = tmp->next;
        pl->position = -1;
    }else{
        pl->head = tmp->next;
        tmp->next->previous = tmp->previous;
    }
    *pe = tmp->entry;
    free(tmp);
    pl->size--;
}
void replaceList(DataType e, int pos, List *pl){
    if(pos > pl->position){
        while(pl->position < pos){
            pl->current = pl->current->next;
            pl->position++;
        }
    }else{
        while(pl->position > pos){
            pl->current = pl->current->previous;
            pl->position--;
        }
    }
    pl->current->entry.value = e;
}
void retrieveList(DataType *pe, int pos, List *pl){
    if(pos <= pl->position){
        while(pl->position > pos){
            pl->current = pl->current->previous;
            pl->position--;
        }
    }else{
        while(pl->position < pos){
            pl->current = pl->current->next;
            pl->position++;
        }
    }
    *pe = pl->current->entry.value;
}
void traverseList(List *pl,void (*pf)(ListEntry*)){
    ListNode *pn = pl->head;
    while(pn){
        (*pf)(&pn->entry);
        pn = pn->next;
    }
}
