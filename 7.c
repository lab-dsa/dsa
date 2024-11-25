#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;
NODE *root = NULL;

// Function to create and insert a node into the BST
void create(int x)
{
    NODE *temp, *prev, *cur;
    temp = (NODE *)malloc(sizeof(NODE));
    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    temp->left = NULL;
    temp->right = NULL;
    temp->info = x;

    if (root == NULL)
    {
        root = temp;
        return;
    }

    prev = NULL;
    cur = root;

    while (cur != NULL)
    {
        prev = cur;
        if (x < cur->info)
            cur = cur->left;
        else if (x > cur->info)
            cur = cur->right;
        else
        {
            printf("\nDuplicate value not allowed.\n");
            free(temp); // Free memory allocated for duplicate value
            return;
        }
    }

    if (x < prev->info)
        prev->left = temp;
    else
        prev->right = temp;
}

// Preorder traversal (root, left, right)
void preorder(NODE *root)
{
    if (root != NULL)
    {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal (left, root, right)
void inorder(NODE *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

// Postorder traversal (left, right, root)
void postorder(NODE *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}

int main()
{
    int item, choice;

    while (1)
    {
        printf("\n..... Binary Search Tree Operations .....\n");
        printf("1. Create\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &item);
            create(item);
            break;

        case 2:
            printf("\nPreorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 3:
            printf("\nInorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 4:
            printf("\nPostorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 5:
            exit(0);

        default:
            printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}
