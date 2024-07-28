#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *del_last_node(struct node *head)
{
    struct node *temp = head;
    struct node *temp2;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp2 = temp->prev;
    temp2->next = NULL;
    free(temp);
    temp = NULL;
    return head;
}
struct node *del_first_node(struct node *head)
{
    head = head->next;
    free(head->prev);
    return head;
}
struct node *add_to_empty(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}
struct node *add_at_end(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr;
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}
struct node *del_n_node(struct node *head, int position)
{
    struct node *temp = head;
    struct node *temp2 = NULL;
    if (position == 1)
    {
        head = del_first_node(head);
        return head;
    }
    while (position > 1)
    {
        temp = temp->next;
        position--;
    }
    if (temp->next == NULL)
    {
        head = del_last_node(head);
        return head;
    }
    else
    {
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
        temp = NULL;
        return head;
    }
}
int main()
{
    struct node *head = NULL;
    head = add_to_empty(head, 45);
    head = add_at_end(head, 9);
    head = add_at_end(head, 60);
    head = del_n_node(head, 2);

    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}