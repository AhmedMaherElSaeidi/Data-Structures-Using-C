#include <stdio.h>
#include <stdlib.h>
#include "List.h"

void display(ListEntry *pe){
    printf("%c\n", *pe);
}
int main()
{
    List l;
    createList(&l);

    int i = 0;
    char c = getchar();
    while(!listFull(&l) && c != '\n'){
        insertList(c,i,&l);
        c = getchar();
        i++;
    }

    replaceList('k',2,&l);
    retrieveList(&c,2,&l);
    printf("List size is %d\n",listSize(&l));
    printf("List[2] is %c\n",c);

    i=listSize(&l) - 1;
    while(!listEmpty(&l)){
        deleteList(&c,i,&l);
        printf("%c\n",c);
        i=listSize(&l) - 1;
    }

    traverseList(&l, display);
    printf("List size is %d\n",listSize(&l));
    return 0;
}
