#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

ListNode *createListNode(int val) {
    ListNode *n = (ListNode *)malloc(sizeof(ListNode));
    if (NULL != n) {
        n->val = val;
        n->next = NULL;
    }
    return n;
}

ListNode *createListNodeFromArray(int *arr, int n) {
    int i;
    ListNode *head,*tmp,*pre;

    head = tmp = NULL;
    for (i=0; i< n;i++) {
        tmp = createListNode(arr[i]);
        if (NULL == head) {
            head = tmp;
            pre = tmp;
        }
        
        pre->next = tmp;
        pre = pre->next;
    }

    return head;
}

LinkList *createLinkList() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    if (NULL != l) {
        l->count = 0;
        l->head = NULL;
        l->tail = NULL;
    }

    return l;
}

LinkList *headInsert(LinkList *l, ListNode *n) {
    if (NULL == l || NULL == n) {
        return l;
    }

    if (NULL == l->head) {
        l->head = n;
        l->tail = n;
    } else {
        n->next = l->head;
        l->head = n;
    }
    l->count++;
    return l;
}

LinkList *tailInsert(LinkList *l, ListNode *n) {
    if (NULL == l || NULL == n) {
         return l;
     }
 
     if (NULL == l->head) {
         l->head = n;
         l->tail = n;
     } else {
         l->tail->next = n;
         l->tail = n;
     }
     l->count++;
     return l;
}

void freeListNodeValue (ListNode *n) {
    if (NULL == n) {
        return;
    }

}

void freeLinkList(LinkList *l) {
    if (NULL == l) {
        return;
    }

    ListNode *h,*k;
    h = l->head;

    while (h) {
        k = h->next;
        freeListNodeValue(h);
        free(h);
        h = k;
    }

    free(l);
}

void printLinkList(LinkList *l, char * (*printListNodeValue) (void *v)) {
    printListNode(l->head);
}

void printListNode(ListNode *head) {
    ListNode *n = head;

    if (head == NULL) {
        printf("empty\n");
    }

    while (n && n->next) {
        printf("%d->", n->val);
        n = n->next;
    }

    printf("%d\n", n->val);
}
