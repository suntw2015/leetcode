/* 
 * https://leetcode.com/problems/rotate-list/
 */
#include <stdio.h>
#include "LinkList.h"

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next) {
    	return head;
    }

    int i,n;
    struct ListNode *tmp,*newHead,*newTail;

    n = 0;
    tmp = head;
    while (tmp) {
    	n++;
    	tmp = tmp->next;
    }

    k = k % n;
    if (k == 0) {
    	return head;
    }

    i = 1;

    tmp = head;
    while (tmp && tmp->next) {
    	if (i == n - k) {
    		newTail = tmp;
    		newHead = tmp->next;
    	}
    	i++;
    	tmp = tmp->next;
    }

	newTail->next = NULL;
    tmp->next = head;
    return newHead;
}

int main () {
	ListNode *head;
	int a[] = {1,2,3,4,5,6,7,8};

	head = createListNodeFromArray(a, sizeof(a)/sizeof(int));
	head = rotateRight(head, 3);
	printListNode(head);
	return 0;
}