/*
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 */

#include <stdio.h>
#include "LinkList.h"

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    struct ListNode *tmp,*start;
    start = tmp = head;

    while (tmp) {
        if (tmp != start && tmp->val != start->val) {
            start->next = tmp;
            start = tmp;
        }
        
        tmp = tmp->next;
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