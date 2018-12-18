/*
 *
 */

#include <stdio.h>
#include "LinkList.h"

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    struct ListNode *tmp,*start,*newHead,*last;
    int repeatCount = 0;

    start = tmp = head;
    newHead = NULL;

    while (tmp) {
        if (tmp != start && tmp->val != start->val) {
            //只有一个
            if (repeatCount == 0) {
                if (!newHead) {
                    newHead = start;
                }
                if (last) {
                    last->next = start;
                } else {
                    last = start;
                }
            }
            start->next = tmp;
            start = tmp;
            repeatCount = 0;
        }
        
        tmp = tmp->next;
        repeatCount++;
    }

    start->next = NULL;

    return head;
}

int main () {
    ListNode *head;
    int a[] = {1,1,2,3,3,5,5,8,8,8,8,10};
    head = createListNodeFromArray(a, sizeof(a)/sizeof(int));
    head = deleteDuplicates(head);
    printListNode(head);
    return 0;
}