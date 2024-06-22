#include "List.h"
// List - Array based "c file"

void createList(List *pl){
    pl->size = 0;
}
void clearList(List *pl){
    pl->size = 0;
}

int listSize(List *pl){
    return pl->size;
}
int listEmpty(List *pl){
    return !pl->size;
}
int listFull(List *pl){
    return pl->size == MAX;
}

void insertList(ListEntry e, int index, List *pl){
    for(int i = pl->size ; i > index ; i--)
        pl->entry[i] = pl->entry[i-1];
    pl->entry[index] = e;
    pl->size++;
}
void replaceList(ListEntry e, int index, List *pl){
    pl->entry[index] = e;
}
void deleteList(ListEntry *pe, int index, List *pl){
    *pe = pl->entry[index];
    for(int i = index + 1 ; i < pl->size; i++)
        pl->entry[i-1] = pl->entry[i];
    pl->size--;
}
void retrieveList(ListEntry *pe, int index, List *pl){
    *pe = pl->entry[index];
}
void traverseList(List *pl,void (*pf)(ListEntry*)){
    for(int i = 0 ; i < pl->size ; i++)
        (*pf)(&pl->entry[i]);
}
