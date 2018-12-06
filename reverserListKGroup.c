#include <stdio.h>
#include "LinkList.h"

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    ListNode *tmp,*pre,*next,*cur,*preGroup,*start,*end;
    int i;

    if (head == NULL) {
        return head;
    }

    preGroup = tmp = pre = cur = next = NULL;
    i = 1;

    tmp = head;
    cur = head;
    while (tmp) {
        if (i == k) {
            next = tmp->next;
            //翻转cur->tmp
            start = cur;
            end = tmp;
            
            pre = NULL;
            cur = start;

            while (cur) {
                next = cur->next;
                cur->next = pre;

                pre = cur;
                cur = next;
            }

            if (NULL != preGroup) {
                preGroup->next = pre;
            }

            cur = next;
            pre = tmp;
            i = 1;
        }
        tmp = tmp->next;
        i++;
    }
}

int main () {
    LinkList *head;
    int a[] = {1,2,3,4,5,6,7,8,9};
    head = createListNodeFromArray(a, sizeof(a)/sizeof(int));
    head = reverseKGroup(head, 2);
    printListNode(head);
    return 0;
}