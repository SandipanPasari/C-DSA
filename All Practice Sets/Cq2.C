#include <stdio.h>
#include <stdlib.h>
#define MAX

int cqueue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data);
int dequeue();
int peek();
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
        printf("3. Print the first element\n");
        printf("4. Print all elements\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be added in the Queue : ");
            scanf("%d", &data);
            enqueue(data);
            printf("Data is Successfully added to the Queue\n");
            break;
        case 2:
            data = dequeue();
            printf("Element Deleted from the Queue is %d\n", data);
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
    }
    return 0;
}

int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if ((front == 0 & rear == MAX - 1) || (front == rear + 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int data)
{
    
}