#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void print_nodes(struct node *head)
{
    if (head == NULL)
        printf("Empty Node");
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &head->data);
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &current->data);
    current->link = NULL;
    head->link = current;

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for the new node : ");
    scanf("%d", &newnode->data);
    newnode->link = head;
    head = newnode;

    print_nodes(head);
    return 0;
}