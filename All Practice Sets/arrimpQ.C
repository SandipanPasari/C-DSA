#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX];
int rear = -1;
int front = -1;

void enqueue(int);
int dequeue();
int isFull();
int isEmpty();
void print();
int peek();

int main()
{
    int choice, data;
    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print the first element\n");
        printf("4. Print all elements\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be added to the queue : ");
            scanf("%d", &data);
            enqueue(data);
            printf("Element is successfully added to the queue.\n");
            break;
        case 2:
            data = dequeue();
            printf("Deleted element is %d\n", data);
            break;
        case 3:
            printf("The first element of the queue is %d\n", peek());
            break;
        case 4:
            print();
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong Choice!!\n");
        }
        return 0;
    }
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue Qverflow");
        exit(1);
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
        printf("Queue Undeflow\n");
        exit(1);
    }
    int data = queue[front];
    front++;
    return data;
}

int isEmpty()
{
    return (front == -1 || front > rear);
}

int isFull()
{
    return (rear == MAX -1);
}

int peek()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    return queue[front];
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