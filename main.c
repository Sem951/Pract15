#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "HelperFuncs.h"

int main()
{
    Node *root = NULL;
    int choice, data, oldVal, newVal;

    while (1)
    {
        system("cls");
        printf("Menu\n"
               "1. Insert node\n"
               "2. Replace node\n"
               "3. Delete node\n"
               "4. Print tree\n"
               "0. Exit\n"
               "Enter your choice");
        choice = range_scan(0, 4);

        switch (choice)
        {
            case 1:
                printf("Enter the data to insert: ");
                data = scan_safe_func_int();
                root = insertNode(root, data);
                break;
            case 2:
                if (root == NULL)
                {
                    printf("Tree is empty!\n");
                    break;
                }
                printf("Enter the old value to replace: ");
                oldVal = scan_safe_func_int();
                printf("Enter the new value: ");
                newVal = scan_safe_func_int();
                replaceNode(root, oldVal, newVal);
                break;
            case 3:
                if (root == NULL)
                {
                    printf("Tree is empty!\n");
                    break;
                }
                printf("Enter the data to delete: ");
                data = scan_safe_func_int();
                root = deleteNode(root, data);
                break;
            case 4:
                if (root == NULL)
                {
                    printf("Tree is empty!\n");
                    break;
                }
                printf("The tree is: ");
                inorderPrint(root);
                printf("\n");
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
        system("pause");
    }
}
