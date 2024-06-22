#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void display(StackEntry *e){
    printf("%c\n",*e);
}

void stackTopUserLevel(StackEntry *e, Stack *ps){
    pop(e,ps);
    push(*e,ps);
}

int main()
{
    Stack s;
    createStack(&s);

    char c;
    c = getchar();

    while(!stackFull(&s) && c != '\n'){
        push(c,&s);
        c = getchar();
    }

    stackTop(&c,&s);
    printf("Stack size is : %d\n", stackSize(&s));
    printf("last element in stack is : %c\n", c);

//    while(!stackEmpty(&s)){
//        pop(&c,&s);
//        printf("%c\n",c);
//    }

    stackTraverse(&s,display);

    return 0;
}
