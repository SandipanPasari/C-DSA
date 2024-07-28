#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
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

    struct node *newnode = (struct node *)malloc(sizeof(struct node *));
    printf("Enter data for the newnode : ");
    scanf("%d", &newnode->data);
    newnode->link = head;
    head = newnode;

    if (head == NULL)
    {
        printf("Empty Node !!");
    }
    struct node *ptr;
    ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}