#include "DoubleLinkedList.h"
#include <stdlib.h>

void createList(List *pl){
    pl->current = NULL;
    pl->position = -1;
    pl->size = 0;
}
void clearList(List *pl){
    while(pl->current){
        if(!pl->current->previous)
            break;
        pl->current = pl->current->previous;
    }

    ListNode *pn = pl->current;
    while(pl->current){
        pn = pn->next;
        free(pl->current);
        pl->current = pn;
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

int insertList(ListEntry e, int pos, List *pl){
    ListNode *pn;
    if(pn = (ListNode*)malloc(sizeof(ListNode))){
        pn->entry = e;
        if(pl->position == -1){
            pn->next = NULL;
            pn->previous = NULL;
            pl->current = pn;
            pl->position++;
        }else if(pos <= pl->position){
            while(pl->position > pos){
                pl->current = pl->current->previous;
                pl->position--;
            }
            pn->next = pl->current;
            pn->previous = pl->current->previous;
            if(pl->current->previous)
                pl->current->previous->next = pn;
            pl->current->previous = pn;
            pl->position++;
        }else{
            while(pl->position < pos - 1){
                pl->current = pl->current->next;
                pl->position++;
            }
            pn->next = pl->current->next;
            pn->previous = pl->current;
            if(pl->current->next)
                pl->current->next->previous = pn;
            pl->current->next = pn;
        }
        pl->size++;
        return 1;
    }
    return 0;
}

void replaceList(ListEntry e, int pos, List *pl){
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
    pl->current->entry = e;
}
void deleteList(ListEntry *pe, int pos, List *pl){
    ListNode *tmp;

    if(pos == 0){
        while(pl->position > pos){
            pl->current = pl->current->previous;
            pl->position--;
        }
        if(pl->current->next){
            tmp = pl->current;
            *pe = tmp->entry;
            pl->current = tmp->next;
            pl->current->previous = tmp->previous;
            free(tmp);
        }else{
            tmp = pl->current;
            *pe = tmp->entry;
            pl->current = tmp->previous;
            pl->position--;
            free(tmp);
        }
    }else{
        if(pos <= pl->position){
            while(pl->position > pos - 1){
                pl->current = pl->current->previous;
                pl->position--;
            }
        }else{
            while(pl->position < pos - 1){
                pl->current = pl->current->next;
                pl->position++;
            }
        }
        tmp = pl->current->next;
        *pe = tmp->entry;
        pl->current->next = tmp ->next;
        if(tmp->next)
            tmp->next->previous = pl->current;
        free(tmp);
    }
    pl->size--;
}

void retrieveList(ListEntry *pe, int pos, List *pl){
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
    *pe = pl->current->entry;
}
void traverseList(List *pl,void (*pf)(ListEntry*)){
    ListNode *pn = pl->current;
    while(pn){
        if(!pn->previous)
            break;
        pn = pn->previous;
    }
    while(pn){
        (*pf)(&pn->entry);
        pn = pn->next;
    }
}
