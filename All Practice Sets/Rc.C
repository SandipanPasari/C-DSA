#include <stdio.h>
#include <stdlib.h>
#define size 10

int front = -1;
int rear = -1;
int queue[size];

void enqueue(int data)
{
    if ((rear + 1) % size == front)
    {
        printf("Queue Overflow");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = data;
        printf("%d is inserted in queue", data);
    }
    else
    {
        rear = (rear + 1) % size;
        queue[rear] = data;
        printf("%d is inserted in queue", data);
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow");
    }
    else
    {
        printf("%d is deleted from queue", queue[front]);
        front = (front + 1) % size;
    }
}

void display()
{
    for (int i = front; i < rear; i++)
    {
        printf("%d", queue[i]);
    }
}

int main()
{
    int ele;
    char ch;
    while (ch != 'd')
    {
        printf("Enter Choice : 1.Enqueue, 2.Dequeue, 3.Display, 4.Exit\n");
        scanf("%c", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Element");
            scanf("%d", &ele);
            enqueue(ele);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exit");
            break;
        default:
            printf("choice is invalid");
        }
    }
    return 0;
}