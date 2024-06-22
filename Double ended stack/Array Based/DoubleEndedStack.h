#define MAX 20
// Double Ended Stack - Array based "HEADER file"

typedef char DESType;
typedef struct doubleendedstack{
    int size;
    int top;
    int down;
    DESType entry[MAX];
}DEStack;

void createDE(DEStack*);
void clearDE(DEStack*);

int DESize(DEStack*);
int DEFull(DEStack*);
int DEEmpty_down(DEStack*);
int DEEmpty_top(DEStack*);

void DEPush_down(DEStack*,DESType);
void DEPush_top(DEStack*,DESType);
void DEPop_down(DEStack*,DESType*);
void DEPop_top(DEStack*,DESType*);
void DERetrieve_down(DEStack*,DESType*);
void DERetrieve_top(DEStack*,DESType*);

void DETraverse_down(DEStack*,void (*pf)(DESType*));
void DETraverse_top(DEStack*,void (*pf)(DESType*));

