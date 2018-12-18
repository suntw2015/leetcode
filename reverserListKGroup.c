#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    ListNode *tmp,*pre,*next,*cur,*preGroup,*nextGroup,*start,*end,*newHead;
    int i;

    if (head == NULL) {
        return head;
    }

    newHead = preGroup = tmp = pre = cur = next = NULL;
    i = 1;

    tmp = head;
    while (tmp) {
        if (i == 1) {
            start = tmp;
        }

        if (i == k) {
            nextGroup = tmp->next;
            
            cur = start;
            pre = NULL;
            while (i--) {
                next = cur->next;
                cur->next = pre;

                pre = cur;
                cur = next;
            }

            if (NULL != preGroup) {
                preGroup->next = pre;
            }

            if (NULL == newHead) {
                newHead = pre;
            }

            tmp = nextGroup;
            preGroup = start;
            i = 1;
            continue;
        }
        tmp = tmp->next;
        i++;
    }

    if (nextGroup != NULL) {
        preGroup->next = nextGroup;
    }

    return newHead;
}

int main () {
    ListNode *head;
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    head = createListNodeFromArray(a, sizeof(a)/sizeof(int));
    head = reverseKGroup(head, 4);
    printListNode(head);
    return 0;
}
