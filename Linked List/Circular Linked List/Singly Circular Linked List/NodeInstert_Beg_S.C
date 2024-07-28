#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *add_to_empty(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}
struct node *add_to_beg(struct node *tail, int data)
{
    struct node *newP = (struct node *)malloc(sizeof(struct node));
    newP->data = data;
    newP->next = tail->next;
    tail->next = newP;
    return tail;
}
int main()
{
    struct node *tail;
    tail = add_to_empty(45);
    tail = add_to_beg(tail, 20);

    struct node *ptr;
    ptr = tail->next;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);

    return 0;
}