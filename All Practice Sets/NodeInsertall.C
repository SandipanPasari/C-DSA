#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *node_end(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    struct node *ptr;
    ptr = head;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
    return head;
}
struct node *node_nth(struct node *head, int data, int position)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node ));
    struct node *ptr;
    ptr = head;
    temp->data = data;
    temp->link = NULL;

    // position--;
    while (position > 2)
    {
        ptr = ptr->link;
        position--;
    }
    temp->link = ptr->link;
    ptr->link = temp;
    return head;
}
struct node *print_node(struct node *head)
{
    if (head == NULL)
    {
        printf("No node is present !!");
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    return head;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &head->data);
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &current->data);
    head->link = current;
    current->link = NULL;

    current = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &current->data);
    current->link = NULL;
    head->link->link = current;

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data (Beg): ");
    scanf("%d", &newnode->data);
    newnode->link = head;
    head = newnode;

    int enddata;
    printf("Enter Data (End) : ");
    scanf("%d", &enddata);
    head = node_end(head, enddata);

    int n;
    printf("Enter Data (nth) : ");
    scanf("%d", &n);
    int pos;
    printf("Enter position : ");
    scanf("%d", &pos);
    head = node_nth(head, n, pos);

    head = print_node(head);
    return 0;
}