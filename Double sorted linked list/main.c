#include <stdio.h>
#include <stdlib.h>
#include "DoubleSortedLinkedList.h"

void display(ListEntry *pe){
    printf("%c ---> %d\n", pe->value,pe->key);
}
int main()
{
    List l;
    int i = 5;
    ListEntry c;
    createList(&l);

    c.key = i;
    c.value = getchar();
    while(!listFull(&l) && c.value != '\n'){
        insertList(c,&l);
        c.key = i++;
        c.value = getchar();
    }


    c.key =0;
    c.value = '1';
    insertList(c,&l);
    c.key = -1;
    c.value = '2';
    insertList(c,&l);
    c.key = listSize(&l);
    c.value = '3';
    insertList(c,&l);
    c.key = 3;
    c.value = '4';
    insertList(c,&l);

    printf("---- TRAVERSE -----\n");
    printf("List size is %d\n",listSize(&l));
    traverseList(&l,display);

    printf("---- RETRIEVE & REPLACE -----\n");
    retrieveList(&c.value,4,&l);
    printf("< %c >\n",c.value);
    retrieveList(&c.value,7,&l);
    printf("< %c >\n",c.value);
    retrieveList(&c.value,7,&l);
    printf("< %c >\n",c.value);
    retrieveList(&c.value,0,&l);
    printf("< %c >\n",c.value);

    replaceList('#',0,&l);
    replaceList('#',5,&l);
    replaceList('#',4,&l);

    //clearList(&l);
    printf("---- DELETE -----\n");
    while(!listEmpty(&l)){
        deleteList(&c,&l);
        printf("%c\n",c.value);
    }

    printf("---------\n");
    printf("List size is %d\n",listSize(&l));
    traverseList(&l,display);
    return 0;
}
