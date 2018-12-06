#include <stdio.h>
#include "LinkList.h"

char *printIntVal(void *v)
{
    char *a = (char*)malloc(sizeof(char)*100);
    memset(a,0,100*sizeof(char));
    sprintf(a, "%d", *((int *)v));
    return a;
}

int main()
{
    int i;
    LinkListNode *n;
    LinkList *l = createLinkList();

    for(i=0;i<5;i++) {
        n = createLinkListNode();
        n->val = (int *)malloc(sizeof(int));
        *((int *)(n->val)) = i;
        headInsert(l,n);
    }

    printLinkList(l ,printIntVal);
    freeLinkList(l);
    return 0;
}
