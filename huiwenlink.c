#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

typedef int bool;

bool isPalindrome(struct ListNode* head) {
    struct ListNode *faster,*slower,*mid,*pre,*cur,*next;
    int flag = 1;

    if (NULL == head) {
        return flag;
    }

    // 找到中点
    faster = slower = head;
    while (faster && slower && faster->next) {
        faster = faster->next;
        if (faster && faster->next) {
            faster = faster->next;
            slower = slower->next;
        }
    }

    printf("mid: %d\n", slower->val);

    // 翻转后半段
    pre = NULL;
    mid = slower;
    cur = mid->next;

    while (cur) {
        next = cur->next;
        cur->next = pre;

        pre = cur;
        cur = next;
    }

    mid->next = pre;

    printListNode(head);

    // 判断0-n/2 n/2-n是否相等
    faster = head;
    slower = slower->next;
    while (faster && slower) {
        if (faster->val != slower->val) {
            flag = 0;
            break;
        }
        faster = faster->next;
        slower = slower->next;
    }

    //再翻转后半段恢复
    pre = NULL;
    cur = mid->next;
    while (cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    mid->next = pre;
    printListNode(head);

    return flag;
}


int main() {
    
    ListNode *head;
    int s = 0;
    //int a[] = {1,2,3,4,4,3,2,1};
    int a[] = {1,2,3,4,3,2,1};
    head = createListNodeFromArray(a,sizeof(a)/sizeof(int));

    printListNode(head);
    s = isPalindrome(head);
    printf("flag is %d\n", s);


    return 0;
}
