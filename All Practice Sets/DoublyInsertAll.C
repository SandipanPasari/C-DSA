#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *empty(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}
struct node *beg(struct node *head, int data)
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
struct node *end(struct node *head, int data)
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
    temp->prev = ptr;
    ptr->next = temp;
    return head;
}
int main()
{
    struct node *head = NULL;

    head = empty(head, 45);
    head = beg(head, 51);
    head = end(head, 2);

    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}