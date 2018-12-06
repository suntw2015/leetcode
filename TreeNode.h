#ifndef TREENODE_H_
#define TREENODE_H_

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int val);
struct TreeNode *createNode();
struct TreeNode *initTreeFromFile(const char *filepath);

void printTree(struct TreeNode *head);
