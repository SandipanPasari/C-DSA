#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *top = NULL;

int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(newnode));
    if (newnode == NULL)
    {
        printf("Stack Overflow");
        exit(1);
    }
    newnode->data = data;
    newnode->link = NULL;

    newnode->link = top;
    top = newnode;
}

int pop()
{
    struct node *temp;
    int value;
    if (isEmpty())
    {
        printf("Stack Underflow");
        exit(1);
    }
    temp = top;
    value = temp->data;
    top = top->link;
    free(temp);
    temp = NULL;
    return value;
}

int peek()
{
    if (isEmpty())
    {
        printf("Stack Underflow");
        exit(1);
    }
    return top->data;
}

void print()
{
    struct node *ptr;
    ptr = top;
    if (isEmpty())
    {
        printf("Stack Underflow");
        exit(1);
    }
    printf("The elements of the stack are : ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

int main()
{
    printf("\n");
    int choice, data;
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element\n");
        printf("4. Print all the elements of the stack\n");
        printf("5. Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed : ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("Deleted Element is %d\n", data);
            break;
        case 3:
            printf("The topmost element of the stack is %d\n", peek());
            break;
        case 4:
            print();
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong Choice\n");
        }
    }
    return 0;
}