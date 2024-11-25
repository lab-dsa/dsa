#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int pri_que[MAX];
int front, rear;

/* Function to create an empty priority queue */
void create()
{
    front = rear = -1;
}

/* Function to insert value into priority queue */
void insert_by_priority(int data)
{
    if (rear >= MAX - 1)
    {
        printf("\nQueue overflow: no more elements can be inserted.\n");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front = rear = 0;
        pri_que[rear] = data;
        return;
    }
    else
    {
        check(data);
        rear++;
    }
}

/* Function to check priority and place element */
void check(int data)
{
    int i, j;

    for (i = 0; i <= rear; i++)
    {
        if (data >= pri_que[i])
        { // Prioritize higher values
            for (j = rear + 1; j > i; j--)
            {
                pri_que[j] = pri_que[j - 1];
            }
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data; // Add at the end if no higher priority is found
}

/* Function to delete an element from queue */
void delete_by_priority(int data)
{
    int i;

    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty: no elements to delete.\n");
        return;
    }

    for (i = 0; i <= rear; i++)
    {
        if (data == pri_que[i])
        { // Find the element
            for (; i < rear; i++)
            { // Shift elements
                pri_que[i] = pri_que[i + 1];
            }

            pri_que[rear] = -99; // Reset last element
            rear--;

            if (rear == -1) // Reset queue if it becomes empty
                front = -1;

            printf("\n%d deleted from the queue.\n", data);
            return;
        }
    }
    printf("\n%d not found in queue to delete.\n", data);
}

/* Function to display queue elements */
void display_pqueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nElements in the queue are: ");
    for (int i = front; i <= rear; i++)
    { // Loop correctly over the queue
        printf("%d ", pri_que[i]);
    }
    printf("\n");
}

int main()
{
    int n, ch;
    printf("\nPriority Queue Operations:");
    printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - Display queue elements");
    printf("\n4 - Exit");

    create(); // Initialize the queue

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter value to be inserted: ");
            scanf("%d", &n);
            insert_by_priority(n);
            break;
        case 2:
            printf("\nEnter value to delete: ");
            scanf("%d", &n);
            delete_by_priority(n);
            break;
        case 3:
            display_pqueue();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice, please enter a correct choice.\n");
        }
    }

    return 0;
}
