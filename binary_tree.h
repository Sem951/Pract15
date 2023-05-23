#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data);
Node *insertNode(Node *root, int data);
Node *deleteNode(Node *root, int data);
void inorderPrint(Node *node);
void replaceNode(Node *root, int oldVal, int newVal);

#endif
