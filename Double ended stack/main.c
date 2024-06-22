#include <stdio.h>
#include <stdlib.h>
#include "DoubleEndedStack.h"

void display(DESType *ps){
    printf("%c\n", *ps);
}
int main()
{
    DEStack s;
    createDE(&s);

    // push down ------
    printf("pushing down >>> ");
    char c = getchar();
    while(!DEFull(&s) && c != '\n'){
        //DEPush_down(&s, c); for array based
        if(!DEPush_down(&s, c))
            return 1;
        c = getchar();
    }
    printf("Stack size is %d\n",DESize(&s));

    //push top -------
    printf("pushing top >>> ");
    c = getchar();
    while(!DEFull(&s) && c != '\n'){
        //DEPush_top(&s, c); for array based
        if(!DEPush_top(&s, c))
            return 1;
        c = getchar();
    }
    printf("Stack size is %d\n",DESize(&s));

    //retrieve-------------
    DERetrieve_down(&s, &c);
    printf("top element in down stack < %c >\n", c);
    DERetrieve_top(&s, &c);
    printf("top element in top stack < %c >\n", c);

//    //pop---------------
//    printf("poping down >>> \n");
//    while(!DEEmpty_down(&s)){
//        DEPop_down(&s, &c);
//        printf("%c\n", c);
//    }
//    printf("Stack size is %d\n",DESize(&s));
//
//    printf("poping top >>> \n");
//    while(!DEEmpty_top(&s)){
//        DEPop_top(&s, &c);
//        printf("%c\n", c);
//    }
//    printf("Stack size is %d\n",DESize(&s));

    //traverse-------------------
    printf("traverse down >>> \n");
    DETraverse_down(&s,display);
    printf("traverse top >>> \n");
    DETraverse_top(&s,display);
    printf("Stack size is %d\n",DESize(&s));
    return 0;
}