#define MAX 20
// List - Array based "header file"

typedef char ListEntry;
typedef struct list{
    int size;
    ListEntry entry[MAX];
}List;

void createList(List *);
void clearList(List *);

int listSize(List *);
int listEmpty(List *);
int listFull(List *);

void insertList(ListEntry, int, List *);
void replaceList(ListEntry, int, List *);
void deleteList(ListEntry *, int, List *);
void retrieveList(ListEntry *, int, List *);
void traverseList(List *,void (*pf)(ListEntry*));
