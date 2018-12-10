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
    cur = head;
    while (tmp) {
        if (i == k) {
            nextGroup = tmp->next;
            //翻转cur->tmp
            start = cur;
            
            pre = NULL;
            cur = start;

            while (cur && cur != tmp->next) {
                next = cur->next;
                cur->next = pre;

                pre = cur;
                cur = next;
            }

            if (NULL != preGroup) {
                preGroup->next = tmp;
            }

            if (NULL == newHead) {
                newHead = pre;
            }

            preGroup = start;
            preGroup->next = nextGroup;
            i = 1;
        }
        tmp = tmp->next;
        i++;
    }

    return newHead;
}

int main () {
    ListNode *head;
    int a[] = {1,2,3,4,5,6,7,8,9};
    head = createListNodeFromArray(a, sizeof(a)/sizeof(int));
    head = reverseKGroup(head, 2);
    printListNode(head);
    return 0;
}