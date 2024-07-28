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
    temp->data = data;
    temp->next = temp;
    temp->prev = temp;
    return temp;
}
struct node *add_at_beg(struct node *tail, int data)
{
    struct node *newP = add_to_empty(data);
    if (tail == NULL)
    {
        return newP;
    }
    else
    {
        struct node *temp = tail->next;
        newP->prev = tail;
        newP->next = temp;
        temp->prev = newP;
        tail->next = newP;
        return tail;
    }
}
struct node *add_at_end(struct node *tail, int data)
{
    struct node *newP = add_to_empty(data);
    if (tail == NULL)
    {
        return newP;
    }
    else
    {
        struct node *temp = tail->next;
        newP->next = temp;
        newP->prev = tail;
        tail->next = newP;
        temp->prev = newP;
        tail = newP;
        return tail;
    }
}
int main()
{
    int data = 74;
    struct node *tail;
    tail = add_to_empty(data);
    tail = add_at_beg(tail, 80);
    tail = add_at_end(tail, 76);

    struct node *ptr;
    ptr = tail->next;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);

    return 0;
}