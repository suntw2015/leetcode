#include <stdio.h>
#include <stdlib.h>
//判断链表是否交叉

typedef struct ListNode {
     int val;
     struct ListNode *next;
}ListNode;

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tmpA,*tmpB,*tmpC;
    
    tmpA = headA;
    tmpB = headB;
    
    while(tmpA && tmpB) {
        if (tmpA == tmpB) {
            return tmpA;
        }
        
        tmpA = tmpA->next;
        tmpB = tmpB->next;
    }
    
    if (tmpA != tmpB) {
        //长度不同
        if (NULL == tmpA) {
            tmpC = headB;
            while (tmpB) {
                tmpB = tmpB->next;
                tmpC = tmpC->next;
            }
            tmpA = headA;
            tmpB = tmpC;
        } else {
            tmpC = headA;
            while (tmpA) {
                tmpA = tmpA->next;
                tmpC = tmpC->next;
            }
            tmpA = tmpC;
            tmpB = headB;
        }
    } else {
        //长度相等 且没找到
        return NULL;
    }
    
    //长的先走
    while (tmpA && tmpB) {
        if (tmpA == tmpB) {
            return tmpA;
        }
        
        tmpA = tmpA->next;
        tmpB = tmpB->next;
    }
    
    return NULL;
}

void printList(ListNode *node) {
    ListNode *tmp = node;
    while (tmp && tmp->next) {
        printf("%d->", tmp->val);
        tmp = tmp->next;
    }

    printf("%d\n", tmp->val);
}

void freeList (ListNode **node) {
    ListNode *tmp = *node;
    ListNode *next;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }

    free (node);
}

ListNode *createNode(int val) {
    ListNode *n;
    n = (ListNode*)malloc(sizeof(ListNode));
    n->val = val;
    n->next = NULL;
    return n;
}

int main() {
    int i;
    ListNode *head1,*head2,*n1,*n2,*n3,*n4,*n5,*n6,*n7,*n8;

    head1 = createNode(1);
    head2 = createNode(0);

    n2 = createNode(2);
    n3 = createNode(3);
    n4 = createNode(4);
    n5 = createNode(5);
    n6 = createNode(6);
    n7 = createNode(7);
    n8 = createNode(8);

    head1->next = n3;
    n2->next = n3;
    n3->next = n6;
    head2->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;

    printList(head1);
    printList(head2);

    n1 = getIntersectionNode(head1, head2);
    if (NULL == n1) {
        printf("no intersection\n");
    } else {
        printf("intersection:%d\n",n1->val);
    }

    return 0;
}
