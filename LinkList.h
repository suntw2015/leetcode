typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

typedef struct LinkList {
    int count;
    ListNode *head;
    ListNode *tail;
}LinkList;

ListNode *createListNode(int val);
ListNode *createListNodeFromArray(int *arr, int n);
LinkList *createLinkList();
LinkList *headInsert(LinkList *l, ListNode *n);
LinkList *tailInsert(LinkList *l, ListNode *n);

void printListNode(ListNode *head);
void printLinkList(LinkList *l, char * (*printLinkValue) (void *v));

