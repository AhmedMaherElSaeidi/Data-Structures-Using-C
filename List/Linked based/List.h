// List - Linked based "header file"

typedef char ListEntry;
typedef struct listnode{
    struct listnode *next;
    ListEntry entry;
}ListNode;

typedef struct list{
    struct listnode *head;
    int size;
}List;

void createList(List *);
void clearList(List *);

int listSize(List *);
int listEmpty(List *);
int listFull(List *);

int insertList(ListEntry, int, List *);
void replaceList(ListEntry, int, List *);
void deleteList(ListEntry *, int, List *);
void retrieveList(ListEntry *, int, List *);
void traverseList(List *,void (*pf)(ListEntry*));
