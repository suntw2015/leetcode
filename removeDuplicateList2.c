/*
 *
 */

#include <stdio.h>
#include "LinkList.h"

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    struct ListNode *last,*newHead,*pre,*cur,*next;

    newHead = last = pre = NULL;
    cur = head;
    next = cur->next;

    while (cur) {
        if ((!pre || cur->val != pre->val) && (!next || cur->val != next->val)) {
            if (!newHead) {
                newHead = last = cur;
            } else {
                last->next = cur;
                last = cur;
            }
        }

        pre = cur;
        cur = cur->next;
        if (next) {
            next = cur->next;
        }
    }
    
    if (last) {
        last->next = NULL;
    }

    return newHead;
}

int main () {
    ListNode *head;
    int a[] = {1,1,3,3,5,5,8,8,8,8};
    head = createListNodeFromArray(a, sizeof(a)/sizeof(int));
    head = deleteDuplicates(head);
    printListNode(head);
    return 0;
}