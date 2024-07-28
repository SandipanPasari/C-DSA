#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *front = NULL, *rear = NULL;

void enqueue(int);
int dequeue();
int peek();
void print();
// int isFull(); // no need for linked list implimentation
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
            printf("Deleted element is %d\n", data);
            break;
        case 3:
            print();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong Choice!!\n");
        }
    }
    return 0;
}

void enqueue(int n)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("No Space\n");
        exit(1);
    }
    temp->data = n;
    temp->link = NULL;

    if (rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }
}

int dequeue()
{
    int data;
    struct node *temp;
    if (isEmpty())
    {
        printf("Queue underflow\n");
        exit(1);
    }
    temp = front;
    data = temp->data;
    front = front->link;

    free(temp);
    temp = NULL;
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
        printf("Queue Underflow\n");
        exit(1);
    }
    printf("Queue: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}