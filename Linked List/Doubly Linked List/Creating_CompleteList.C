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
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}
struct node *add_to_end(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *tp;
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    tp = head;
    while (tp->next != NULL)
        tp = tp->next;
    tp->next = temp;
    temp->prev = tp;
    return head;
}
struct node *create(struct node *head)
{
    int n, data, i;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);

    if (n == 0)
        return head;

    printf("Enter the element of node 1 : ");
    scanf("%d", &data);
    head = add_to_empty(head, data);
    for (i = 1; i < n; i++)
    {
        printf("Enter the element for the node %d : ", i + 1);
        scanf("%d", &data);
        head = add_to_end(head, data);
    }
    return head;
}
int main()
{
    struct node *head = NULL;
    head = create(head);
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    ptr = head;
    return 0;
}