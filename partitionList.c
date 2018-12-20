#include <stdio.h>
#include "LinkList.h"

struct ListNode* partition(struct ListNode* head, int x) {
    if (!head || !head->next) {
        return head;
    }

    struct ListNode *small,*lastSmall,*big,*lastBig,*tmp;
    small = big = lastSmall = lastBig = NULL;
    tmp = head;

    while (tmp) {
        if (tmp->val < x) {
            if (!small) {
                small = lastSmall = tmp;
            } else {
                lastSmall->next = tmp;
                lastSmall = tmp;
            }
        } else {
            if (!big) {
                big = lastBig = tmp;
            } else {
                lastBig->next = tmp;
                lastBig = tmp;
            }
        }
        tmp = tmp->next;
    }

    if (small) {
        lastSmall->next = big;
    } else {
        small = big;
    }

    if (lastBig) {
        lastBig->next = NULL;
    }

    return small;
}

int main() {
    ListNode *head;
    int a[] = {1,1};
    head = createListNodeFromArray(a, sizeof(a)/sizeof(int));
    head = partition(head, 2);
    printListNode(head);
    return 0;
}