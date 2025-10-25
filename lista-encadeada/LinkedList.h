
typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} LinkedList;

LinkedList* create();
int appendFirst(LinkedList *l, int value);
int appendLast(LinkedList *l, int value);
int popFirst(LinkedList *l);
int popLast(LinkedList *l);
int destroy(LinkedList *l);
int contains(LinkedList *l, int value);
void print(LinkedList *l);

int length(LinkedList *l);
int insertvalue(LinkedList *l, int index, int value);
int removeValue(LinkedList *l, int index);
