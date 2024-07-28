#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int stack[MAX];
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
    stack[top] = data;
}

int pop()
{
    int value;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    value = stack[top];
    top = top - 1;
    return value;
}

void prime_fact(int num)
{
    int i = 2;
    while (num != 1)
    {
        while (num % i == 0)
        {
            push(i);
            num = num / i;
        }
        i++;
    }
    printf("The prime factors in descending order are : ");
    while (top != -1)
    {
        printf("%d ", pop());
    }
}
int main()
{
    int number;
    printf("Enter a positive number : ");
    scanf("%d", &number);
    prime_fact(number);
    return 0;
}