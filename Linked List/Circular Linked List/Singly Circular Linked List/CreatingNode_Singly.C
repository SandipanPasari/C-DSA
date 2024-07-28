#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *circularSingly(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}
int main()
{
    int data = 9;
    struct node *tail;
    tail = circularSingly(data);

    printf("%d ", tail->data);
    return 0;
}