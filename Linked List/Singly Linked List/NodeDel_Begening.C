#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

struct node *delfirst(struct node *head)
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
    printf("Enter Data : ");
    scanf("%d", &head->data);
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &current->data);
    current->link = NULL;
    head->link = current;

    current = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &current->data);
    current->link = NULL;
    head->link->link = current;

    head = delfirst(head);

    
    if (head == NULL)
    {
        printf("Empty Node ");
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