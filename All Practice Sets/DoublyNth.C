#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *add_to_empty(struct node *newP, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    newP = temp;
    return newP;
}
struct node *add_beforepos(struct node *head, int data, int position)
{
    struct node *newP = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;
    newP = add_to_empty(newP, data);
    while (position > 2)
    {
        temp = temp->next;
        position--;
    }
    if (position == 1)
    {
        newP = add_to_empty(newP, data);
    }
    else
    {
        temp2 = temp->next;
        temp->next = newP;
        temp2->prev = newP;
        newP->next = temp2;
        newP->prev = temp;
    }
    return head;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 45;
    head->next = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->prev = head;
    current->data = 50;
    current->next = NULL;
    head->next = current;

    struct node *current2 = (struct node *)malloc(sizeof(struct node));
    current2->prev = current;
    current2->data = 3;
    current2->next = NULL;
    current->next = current2;

    head = add_beforepos(head, 99, 3);

    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}