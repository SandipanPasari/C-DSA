#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *node_insert_begening(struct node *head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->link = head;
    head = newnode;
    return head;
}

void print(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

struct node *node_del_begening(struct node *head)
{
    if (head == NULL)
        printf("List is empty ");
    else
    {
        struct node *temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
    }
    return head;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &head->data);
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &current->data);
    current->link = NULL;
    head->link = current;

    current = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &current->data);
    current->link = NULL;
    head->link->link = current;

    head = node_insert_begening(head);
    head = node_del_begening(head);
    print(head);

    return 0;
}
