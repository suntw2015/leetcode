#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int i,emptyCount,minIndex,min,*map;
    struct ListNode *head,*pre,**listTmp;
    
    if (NULL == lists) 
        return NULL;
    
    map = (int *)malloc(sizeof(int)*listsSize);
    listTmp = (struct ListNode**)malloc(sizeof(struct ListNode*)*listsSize);

    emptyCount = 0;
    for (i=0;i<listsSize;i++) {
        listTmp[i] = lists[i];
        map[i] = listTmp[i] == NULL;
        emptyCount += map[i];
    }

    head = pre = NULL;

    while (listsSize -1 > emptyCount) {

        //从所有的链表中获取最小的
        min = -9999;
        for (i = 0; i < listsSize; i++) {
            if (map[i] == 1) {
                continue;
            }

            if (min == -9999 || min > listTmp[i]->val) {
                min = listTmp[i]->val;
                minIndex = i;
            }
        }

        if (NULL == head) {
            head = listTmp[minIndex];
            pre = head;
        } else {
            pre->next = listTmp[minIndex];
            pre = pre->next;
        }

        //最小链表减一
        listTmp[minIndex] = listTmp[minIndex]->next;
        if (listTmp[minIndex] == NULL) {
            emptyCount++;
            map[minIndex] = 1;
        }
    }

    //直接拼接最后一个
    for (i = 0; i < listsSize; i++) {
        if (map[i] == 0) {
            if (NULL == head) {
                head = listTmp[i];
            } else {
                pre->next = listTmp[i];   
            }
            break;
        }
    }

    return head;
}

int main ()
{
    int a[] = {1,4,5,8};
    int b[] = {2,3,7,8};
    int c[] = {1,3,6,10,21};

    ListNode *res,*list[3];
    list[0] = createListNodeFromArray(a, sizeof(a)/sizeof(int));
    list[1] = createListNodeFromArray(b, sizeof(b)/sizeof(int));
    list[2] = createListNodeFromArray(c, sizeof(c)/sizeof(int));
    res = mergeKLists(list, 3);
    // printListNode(list[0]);
    // printListNode(list[1]);
    // printListNode(list[2]);
    printListNode(res);
    return 0;
}