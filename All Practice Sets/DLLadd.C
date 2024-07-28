#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *add_to_empty(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}
struct node *add_at_beg(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}
struct node *add_at_end(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    struct node *ptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}
struct node *add_at_n(struct node *head, int data, int position)
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
struct node *print(struct node *head)
{
    if (head == NULL)
        printf("Node is empty");
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return head;
}
int main()
{
    struct node *head = NULL;
    head = add_to_empty(head, 50);
    head = add_at_beg(head, 85);
    head = add_at_end(head, 1);
    head = add_at_n(head, 80, 3);
    head = print(head);
    return 0;
}