#include <stdio.h>
#include <stdlib.h>
#define MAX 10

char tree[MAX];

void root(char);
void left(char, int);
void right(char, int);
void print();

int main()
{
    root('A');
    return 0;
}

void root(char c)
{
    if (tree[0] != '\0')
    {
        printf("Root element already exists");
    }
    else
    {
        tree[0] = c;
    }
}

void left(char c, int parent)
{
    if (tree[0] == '\0')
    {
        printf("Can't insert %c. Parent of %c doesnot exists\n", c, c);
    }
    else 
    {
        tree [(2 * parent) + 1] = c;
    }
}