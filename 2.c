#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

int f = -1, r = -1, q[MAXSIZE];

// Function to insert an element into the queue
void insert()
{
    int item;
    if (r == MAXSIZE - 1)
    { // Check if the queue is full
        printf("OVERFLOW!!!\n");
    }
    else
    {
        if (f == -1) // If the queue is initially empty, set front to 0
            f = 0;
        printf("Enter the item to be inserted:\n");
        scanf("%d", &item);
        q[++r] = item; // Increment rear and add the item
    }
}

// Function to delete an element from the queue
void delete1()
{
    if (f == -1)
    { // Check if the queue is empty
        printf("UNDERFLOW!!!\n");
    }
    else if (f > r)
    { // Reset queue if all elements are deleted
        f = r = -1;
        printf("UNDERFLOW!!!\n");
    }
    else
    {
        printf("Item deleted = %d\n", q[f++]); // Remove the front element
    }
}

// Function to display the elements in the queue
void display()
{
    int i;
    if (f == -1)
    { // Check if the queue is empty
        printf("UNDERFLOW!!!\n");
    }
    else
    {
        printf("The elements are:\n");
        for (i = f; i <= r; i++)
        { // Display elements from front to rear
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch;
    for (;;)
    { // Infinite loop for the menu
        printf("\n1: INSERT\n2: DELETE\n3: DISPLAY\n4: EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("INSERTION\n");
            insert();
            break;
        case 2:
            printf("DELETION\n");
            delete1();
            break;
        case 3:
            printf("DISPLAY\n");
            display();
            break;
        case 4:
            exit(0); // Exit the program
        default:
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
