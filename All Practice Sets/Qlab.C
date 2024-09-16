#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int);
int dequeue();
void print();
int isFull();
int isEmpty();

int main()
{
    int choice, data;
    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print all elements\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be added in the Queue: ");
            scanf("%d", &data);
            enqueue(data);
            printf("Element is successfully added to the queue.\n");
            break;
        case 2:
            data = dequeue();
            printf("Deleted element is %d", data);
            break;
        case 3:
            print();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Invalid Choice");
        }
    }
    return 0;
}

int isEmpty()
{
    return (front == -1 || front > rear);
}

int isFull()
{
    return (rear == MAX - 1);
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue Overflow");
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = data;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    int data = queue[front];
    front++;
    return data;
}

void print()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}