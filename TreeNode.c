#include <stdio.h>
#include "TreeNode.h"

struct TreeNode *createNode(int val) {
    struct TreeNode *n = createNode();
    if (NULL != n) {
        n->val = val;
    }
    return n;
}

struct TreeNode *createNode() {
    struct TreeNode *n = (struct TreeNode *)malloc(sizeof(TreeNode));
    if (NULL != n) {
        n->val = 0;
        n->left = n->right = 0;
    }
    return n;
}

struct TreeNode *initTreeFromFile(const char *filepath) {

}

void printTree(struct TreeNode *head) {
    
}

void _printTree(struct TreeNode *head,int type) {
        
}

int treeLength (struct TreeNode *head) {
    if (NULL == head) {
        return 0;
    }

    int lenl,lenr;

    lenl = treeLength(head->left);
    lenr = treeLength(head->right);

    return (lenl > lenr ? lenl : lenr) + 1; 
}
