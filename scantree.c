#include <stdio.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    
    if (NULL == root) {
        *returnSize = 0;
        *columnSizes = NULL;
        return NULL;
    }

    struct TreeNode *queue[1000], *tmp;
    int start,end,level,mid,i;
    int **res;

    for (i=0;i<1000;i++) {
        queue[i] = NULL;
    }

    res = (int **)malloc(sizeof(int*)*100);
    *columnSizes = (int *)malloc(sizeof(int)*100);

    for (i =0 ;i< 100;i++) {
        res[i] = NULL;
        (*columnSizes)[i] = 0;
    }
    *returnSize = 100;

    start = end = level =0;
    queue[end++] = root;
    mid = end;
    
    while (end > start) {
        res[level] = (int *)malloc(sizeof(int)*(mid-start));
        (*columnSizes)[level] = mid - start;

        i = 0;
        while (mid > start) {
            res[level][i++] = queue[start]->val;

            if (NULL != queue[start]->left)
                queue[end++ % 1000] = queue[start]->left;
            if (NULL != queue[start]->right)
                queue[end++ % 1000] = queue[start]->right;

            start = (start + 1)%1000;
        }
        level++;
        mid = end;
    }

    *returnSize = level;
    return res;
}

int main()
{
    struct TreeNode n1,n2,n3,n4,n5;

    n1.val = 3;
    n2.val = 9;
    n3.val = 20;
    n4.val = 15;
    n5.val = 7;

    n1.left = &n2;
    n1.right = &n3;
    n2.left = n2.right = NULL;
    n3.left = &n4;
    n3.right = &n5;
    n4.left = n4.right = n5.left = n5.right = NULL;

    int size,*column,**res,i,j;
    column = res = NULL;

    res = levelOrder(&n1,&column,&size);
    
    for (i=0;i<size;i++) {
        for(j=0;j<column[i];j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    if (NULL != column)
        free(column);
    if (res != NULL) {
        for (i=0;i<size;i++) {
            free(res[i]);
        }

        free(res);
    }

    return 0;
}
