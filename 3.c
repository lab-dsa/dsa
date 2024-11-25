#include <stdio.h>
#define MAX 6

int queue[MAX]; // Array declaration
int front = -1;
int rear = -1;

// Function to insert an element in a circular queue
void enqueue(int element)
{
    if ((rear + 1) % MAX == front)
    { // Check if the queue is full
        printf("Queue is overflow..\n");
    }
    else if (front == -1 && rear == -1)
    { // Check if the queue is empty
        front = 0;
        rear = 0;
        queue[rear] = element;
    }
    else
    {
        rear = (rear + 1) % MAX; // Increment rear circularly
        queue[rear] = element;
    }
}

// Function to delete the element from the queue
int dequeue()
{
    if (front == -1 && rear == -1)
    { // Check if the queue is empty
        printf("\nQueue is underflow..\n");
        return -1;
    }
    else if (front == rear)
    { // Single element in the queue
        int dequeuedElement = queue[front];
        printf("\nThe dequeued element is %d\n", dequeuedElement);
        front = -1;
        rear = -1;
        return dequeuedElement;
    }
    else
    {
        int dequeuedElement = queue[front];
        printf("\nThe dequeued element is %d\n", dequeuedElement);
        front = (front + 1) % MAX; // Increment front circularly
        return dequeuedElement;
    }
}

// Function to display the elements of the queue
void display()
{
    if (front == -1 && rear == -1)
    { // Check if the queue is empty
        printf("\nQueue is empty..\n");
    }
    else
    {
        printf("\nElements in the Queue are: ");
        int i = front;
        while (1)
        {
            printf("%d ", queue[i]);
            if (i == rear) // Stop when all elements are printed
                break;
            i = (i + 1) % MAX; // Increment circularly
        }
        printf("\n");
    }
}

int main()
{
    int choice = 1, x; // Variables declaration

    while (choice != 0)
    { // Menu loop
        printf("\nPress 1: Insert an element");
        printf("\nPress 2: Delete an element");
        printf("\nPress 3: Display the elements");
        printf("\nPress 0: Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
