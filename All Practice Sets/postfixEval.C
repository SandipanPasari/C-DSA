#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100

char stack[MAX];
char infix[MAX];
char postfix[MAX];
int top = -1;

void push(char);
char pop();
int isEmpty();
void inToPost();
int space(char);
void print();
int precedence(char);
int post_eval();

int main()
{
    int result;
    printf("Enter the infix expression: ");
    gets(infix);

    inToPost();
    result = post_eval();
    print();
    printf("The result obtained after postfix evaluation is: %d\n", result);
    return 0;
}

void inToPost()
{
    int i, j = 0;
    char symbol, next;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if (!space(symbol))
        {
            switch (symbol)
            {
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while ((next = pop()) != '(')
                        postfix[j++] = next;
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                        postfix[j++] = pop();
                    push(symbol);
                    break;
                default:
                    postfix[j++] = symbol;
            }
        }   
    }
    while (!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int space(char c)
{
    return (c == ' ' || c == '\t');
}

int precedence(char symbol)
{
    switch (symbol)
    {
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void print()
{
    int i = 0;
    printf("The equivalent postfix expression is: ");
    while (postfix[i])
        printf("%c", postfix[i++]);
    printf("\n");
}

void push(char value)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow");
        exit(1);
    }
    stack[++top] = value;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow");
        exit(1);
    }
    return stack[top--];
}

int isEmpty()
{
    return (top == -1);
}

int post_eval()
{
    int i, a, b;
    for (i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
            push(postfix[i]);
        else
        {
            a = pop();
            b = pop();
            switch (postfix[i])
            {
                case '+':
                    push(b + a);
                    break;
                case '-':
                    push(b - a);
                    break;
                case '*':
                    push(b * a);
                    break;
                case '/':
                    push(b / a);
                    break;
                case '^':
                    push(pow(a, b));
                    break;
            }
        }
    }
    return pop();
}