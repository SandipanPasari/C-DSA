#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int stack_arr[MAX];
int top = -1;

int isFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (top == -1)
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
    if (top == MAX - 1)
    {
        printf("Stack Overflow");
        return;
    }
    top = top + 1;
    stack_arr[top] = data;
}

int pop()
{
    int value;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    value = stack_arr[top];
    top = top - 1;
    return value;
}

int peek()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack_arr[top];
}

void print()
{
    printf("\n");
    int i;
    if (top == -1)
    {
        printf("Stack Underflow");
        return;
    }
    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack_arr[i]);
    }
    printf("\n");
}

int main()
{
    int choice, data;
    while (1)
    {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element\n");
        printf("4. Print all the elements of stack\n");
        printf("5. Quit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed : ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("Deleted element is %d\n", data);
            break;
        case 3:
            printf("The topmost element of the stack is %d\n", peek());
            break;
        case 4:
            print();
            break;
        case 5:
            exit(1);
            break;
        }
    }
    return 0;
}
