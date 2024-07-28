#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void printing_node(struct node *head)
{
    if (head == NULL)
        printf("Empty Node");
    struct node *ptr = NULL;
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

    current = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &current->data);
    current->link = NULL;
    head->link->link = current;

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);
    newnode->link = head;
    head = newnode;

    printing_node(head);
    return 0;
}