// Double Ended Stack - Linked based "HEADER file"

typedef char DESType;
typedef struct desnode{
    struct desnode *next;
    DESType entry;
}DESNode;
typedef struct destack{
    int size;
    struct desnode *top;
    struct desnode *down;
}DEStack;

void createDE(DEStack*);
void clearDE(DEStack*);

int DESize(DEStack*);
int DEFull(DEStack*);
int DEEmpty_down(DEStack*);
int DEEmpty_top(DEStack*);

int DEPush_down(DEStack*,DESType);
int DEPush_top(DEStack*,DESType);
void DEPop_down(DEStack*,DESType*);
void DEPop_top(DEStack*,DESType*);
void DERetrieve_down(DEStack*,DESType*);
void DERetrieve_top(DEStack*,DESType*);

void DETraverse_down(DEStack*,void (*pf)(DESType*));
void DETraverse_top(DEStack*,void (*pf)(DESType*));

