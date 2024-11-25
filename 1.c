#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 2 // Define the maximum size of the stack

int s[MAX_SIZE], top = -1;

// Function to push an element into the stack
void push()
{
    int x;
    if (top == MAX_SIZE - 1)
    { // Check if the stack is full
        printf("Stack overflow\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &x);
    top = top + 1;
    s[top] = x;
}

// Function to pop an element from the stack
void pop()
{
    if (top == -1)
    { // Check if the stack is empty
        printf("Stack underflow\n");
        return;
    }
    printf("Popped element is %d\n", s[top]);
    top = top - 1;
}

// Function to display the contents of the stack
void display()
{
    int i;
    if (top == -1)
    { // Check if the stack is empty
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("Contents of the stack:\n");
        for (i = 0; i <= top; i++)
        {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch;
    for (;;)
    { // Infinite loop for menu
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice, please try again\n");
        }
    }
    return 0;
}





