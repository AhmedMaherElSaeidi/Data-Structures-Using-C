typedef char DataType;
typedef struct listentry{
    int key;
    DataType value;
}ListEntry;
typedef struct listnode{
    ListEntry entry;
    struct listnode *next;
    struct listnode *previous;
}ListNode;

typedef struct list{
    int size;
    int position;
    struct listnode *head;
    struct listnode *current;
}List;

void createList(List *);
void clearList(List *);

int listSize(List *);
int listEmpty(List *);
int listFull(List *);

int insertList(ListEntry, List *);
void deleteList(ListEntry *, List *);
void replaceList(DataType, int, List *);
void retrieveList(DataType *, int, List *);
void traverseList(List *,void (*pf)(ListEntry*));
