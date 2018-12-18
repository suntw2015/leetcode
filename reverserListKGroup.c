#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    ListNode *tmp,*pre,*next,*cur,*preGroup,*nextGroup,*start,*newHead;
    int i;

    if (head == NULL || k == 1) {
        return head;
    }

    newHead = preGroup = tmp = pre = cur = next = NULL;
    i = 1;

    start = tmp = head;
    while (tmp) {
        if (i == k) {
            //记录下一组
            nextGroup = tmp->next;
            
            cur = start;
            pre = NULL;
            //翻转当前组
            while (i--) {
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
            tmp = start = nextGroup;
            i = 1;
            continue;
        }
        tmp = tmp->next;
        i++;
    }

    if (nextGroup && preGroup) {
        preGroup->next = nextGroup;
    }
    
    if (!newHead) {
        newHead = head;
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
