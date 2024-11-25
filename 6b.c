#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};

struct node *first = NULL, *cur, *prev, *next;

// Function to insert a node at the front
void insertfront()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->llink = temp->rlink = NULL;

    printf("Enter the node to be inserted: ");
    scanf("%d", &temp->info);

    if (first == NULL)
    {
        first = temp;
        return;
    }

    temp->rlink = first;
    first->llink = temp;
    first = temp;
}

// Function to insert a node before a specific node
void insertleft()
{
    int key;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->llink = temp->rlink = NULL;

    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter the key before which the node is to be inserted: ");
    scanf("%d", &key);
    printf("Enter the node to be inserted: ");
    scanf("%d", &temp->info);

    prev = NULL;
    cur = first;

    while (cur != NULL)
    {
        if (cur->info == key && cur == first)
        {
            temp->rlink = cur;
            cur->llink = temp;
            first = temp;
            return;
        }

        if (cur->info == key)
        {
            temp->rlink = cur;
            temp->llink = prev;
            prev->rlink = temp;
            cur->llink = temp;
            return;
        }

        prev = cur;
        cur = cur->rlink;
    }

    printf("Key not found\n");
}

// Function to delete a node
void Delete1()
{
    int key;
    printf("Enter the node to be deleted: ");
    scanf("%d", &key);

    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (first->rlink == NULL)
    { // Only one node in the list
        if (key == first->info)
        {
            printf("%d node is deleted\n", key);
            free(first);
            first = NULL;
            return;
        }
        else
        {
            printf("Key not found\n");
            return;
        }
    }

    cur = first;
    while (cur != NULL)
    {
        if (cur->info == key)
        {
            if (cur == first)
            { // Deleting the first node
                first = first->rlink;
                first->llink = NULL;
                printf("%d node is deleted\n", key);
                free(cur);
                return;
            }

            if (cur->rlink == NULL)
            { // Deleting the last node
                prev = cur->llink;
                prev->rlink = NULL;
                printf("%d node is deleted\n", key);
                free(cur);
                return;
            }

            // Deleting a middle node
            prev = cur->llink;
            next = cur->rlink;
            prev->rlink = next;
            next->llink = prev;
            printf("%d node is deleted\n", key);
            free(cur);
            return;
        }
        cur = cur->rlink;
    }

    printf("Key not found\n");
}

// Function to display the list
void display()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("List is:\n");
    cur = first;
    while (cur != NULL)
    {
        printf("%d ", cur->info);
        cur = cur->rlink;
    }
    printf("\n");
}

// Main function
int main()
{
    int ch;
    printf("Menu:\n");
    printf("1. Insert at Front\n");
    printf("2. Insert Before a Node\n");
    printf("3. Delete a Node\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    for (;;)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insertfront();
            break;
        case 2:
            insertleft();
            break;
        case 3:
            Delete1();
            break;
        case 4:
            display();
            break;
        default:
            exit(0);
        }
    }

    return 0;
}
