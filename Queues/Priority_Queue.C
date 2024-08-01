#include <stdio.h>
#include <stdlib.h>

struct node
{
    int priority;
    int data;
    struct node *link;
} *front = NULL;

void enqueue(int, int);
int dequeue();
int isEmpty();
void print();

int main()
{
    int choice, data, priority;
    while (1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print all the elements\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be added in the queue : ");
            scanf("%d", &data);
            printf("Enter its priority : ");
            scanf("%d", &priority);
            enqueue(data, priority);
            printf("Element is added in the queue successfully\n");
            break;
        case 2:
            data = dequeue();
            printf("Deleted element is: %d", data);
            break;
        case 3:
            print();
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong Choice");
        }
    }
    return 0;
}

void enqueue(int data, int priority)
{
    struct node *temp = NULL;

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("memory Not Available");
        exit(1);
    }
    newnode->priority = priority;
    newnode->data = data;
    newnode->link = NULL;

    if (isEmpty() || priority < front->priority)
    {
        newnode->link = front;
        front = newnode;
    }
    else
    {
        temp = front;
        while (temp->link != NULL && temp->link->priority <= priority)
        {
            temp = temp->link;
        }
        newnode->link = temp->link;
        temp->link = newnode;
    }
}

int dequeue()
{
    struct node *temp;
    int data;
    if (isEmpty())
    {
        printf("Queue Underflow");
        exit(1);
    }
    else
    {
        temp = front;
        data = temp->data;
        front = front->link;
        free(temp);
        temp = NULL;
    }
    return data;
}

int isEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void print()
{
    struct node *temp;
    temp = front;
    if (isEmpty())
    {
        printf("Queue underflow");
        exit(1);
    }
    else
    {
        printf("Queue is : ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
    }
    printf("\n");
}