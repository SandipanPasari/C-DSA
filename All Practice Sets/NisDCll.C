#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *add_to_empty(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = temp;
    temp->data = data;
    temp->next = temp;
    return temp;
}
struct node *add_at_beg(struct node *tail, int data)
{
    struct node *newnode = add_to_empty(data);
    if (tail == NULL)
    {
        printf("Node is Empty");
    }
    else
    {
        struct node *temp = tail->next;
        newnode->prev = tail;
        temp->prev = newnode;
        newnode->next = temp;
        tail->next = newnode;
        return tail;
    }
}
struct node *add_at_end(struct node *tail, int data)
{
    struct node *newnode = add_to_empty(data);
    if (tail == NULL)
    {
        printf("Empty Node");
    }
    else
    {
        struct node *temp = tail->next;
        newnode->next = temp;
        newnode->prev = tail;
        tail->next = newnode;
        temp->prev = newnode;
        tail = newnode;
        return tail;
    }
}
int main()
{
    struct node *tail;
    int data = 78;
    tail = add_to_empty(data);
    tail = add_at_beg(tail, 62);
    tail = add_at_end(tail, 10);

    struct node *ptr;
    ptr = tail->next;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);
    return 0;
}