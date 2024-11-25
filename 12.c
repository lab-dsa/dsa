#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for Binary Search Tree Node
struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

// Structure for Postfix Expression Tree Node
struct PostfixNode
{
    char data;
    struct PostfixNode *left;
    struct PostfixNode *right;
};

// Function to create a new BST Node
struct BSTNode *createBSTNode(int data)
{
    struct BSTNode *newNode = (struct BSTNode *)malloc(sizeof(struct BSTNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct BSTNode *insertBST(struct BSTNode *root, int data)
{
    if (root == NULL)
        return createBSTNode(data);
    if (data < root->data)
        root->left = insertBST(root->left, data);
    else if (data > root->data)
        root->right = insertBST(root->right, data);
    return root;
}

// Function for in-order traversal of BST
void inorderBST(struct BSTNode *root)
{
    if (root != NULL)
    {
        inorderBST(root->left);
        printf("%d ", root->data);
        inorderBST(root->right);
    }
}

// Function to create a new Postfix Expression Tree Node
struct PostfixNode *createPostfixNode(char data)
{
    struct PostfixNode *newNode = (struct PostfixNode *)malloc(sizeof(struct PostfixNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if a character is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to construct Postfix Expression Tree
struct PostfixNode *constructPostfixTree(char *postfix)
{
    struct PostfixNode *stack[100]; // Stack to hold tree nodes
    int top = -1;

    for (int i = 0; i < strlen(postfix); i++)
    {
        char ch = postfix[i];

        // If the scanned character is an operand
        if (isalnum(ch))
        {
            stack[++top] = createPostfixNode(ch);
        }
        // If the scanned character is an operator
        else if (isOperator(ch))
        {
            struct PostfixNode *node = createPostfixNode(ch);
            node->right = stack[top--]; // Right child
            node->left = stack[top--];  // Left child
            stack[++top] = node;        // Push the subtree back to stack
        }
    }

    return stack[top]; // The root of the Postfix Expression Tree
}

// Function for pre-order traversal of Postfix Expression Tree
void preorderPostfix(struct PostfixNode *root)
{
    if (root != NULL)
    {
        printf("%c ", root->data);
        preorderPostfix(root->left);
        preorderPostfix(root->right);
    }
}

// Main function
int main()
{
    // Binary Search Tree Example
    struct BSTNode *bstRoot = NULL;
    int bstValues[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(bstValues) / sizeof(bstValues[0]);

    for (int i = 0; i < n; i++)
    {
        bstRoot = insertBST(bstRoot, bstValues[i]);
    }

    printf("In-order traversal of BST:\n");
    inorderBST(bstRoot);
    printf("\n");

    // Postfix Expression Tree Example
    char postfix[] = "ab+cde+*"; // Corresponds to ((a+b)(c+d))
    struct PostfixNode *postfixRoot = constructPostfixTree(postfix);

    printf("Pre-order traversal of Postfix Expression Tree:\n");
    preorderPostfix(postfixRoot);
    printf("\n");

    return 0;
}
