#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

void display(ListEntry *pe){
    printf("%c\n", *pe);
}
int main()
{
    List l;
    createList(&l);

    char c = getchar();
    while(!listFull(&l) && c != '\n'){
        insertList(c,listSize(&l),&l);
        c = getchar();
    }

    printf("List size is %d\n",listSize(&l));

//    while(!listEmpty(&l)){
//        deleteList(&c,0,&l);
//        printf("%c\n",c);
//    }

    traverseList(&l, display);
    printf("List size is %d\n",listSize(&l));
    return 0;
}
