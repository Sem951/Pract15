#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"


/**
 * @brief Create a new node
 *
 * @param data The data to store in the new node
 * @return The new node
 */
Node *createNode(int data)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Error creating a new node.\n");
        exit(0);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


/**
 * @brief Insert a new node
 *
 * @param root The root of the tree
 * @param data The data to store in the new node
 * @return The new node
 */
Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    } else if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    } else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}


/**
 * @brief Delete a node
 *
 * @param root The root of the tree
 * @return The new root
 */
Node *findMin(Node *root)
{
    while (root->left != NULL) root = root->left;
    return root;
}


/**
 * @brief Delete a node
 *
 * @param root The root of the tree
 * @param data The data to delete
 * @return The new root
 */
Node *deleteNode(Node *root, int data)
{
    if (root == NULL) return NULL;
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    } else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        } else
        {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}


/**
 * @brief Print the tree
 *
 * @param node The root of the tree
 */
void inorderPrint(Node *node)
{
    if (node == NULL) return;
    inorderPrint(node->left);
    printf("%d ", node->data);
    inorderPrint(node->right);
}


/**
 * @brief Replace a node
 *
 * @param root The root of the tree
 * @param oldVal The old value
 * @param newVal The new value
 */
void replaceNode(Node *root, int oldVal, int newVal)
{
    root = deleteNode(root, oldVal);
    insertNode(root, newVal);
}
