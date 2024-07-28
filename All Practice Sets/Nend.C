#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void add_node_end(struct node *head, int newdata)
{
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = newdata;
    temp->link = NULL;

    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
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

    int newdata;
    printf("Enter new data : ");
    scanf("%d", &newdata);
    add_node_end(head, newdata);

    if (head == NULL)
        printf("Empty Node");
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != 0)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    
    return 0;
}