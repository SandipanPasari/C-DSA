#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void add_at_end(struct node *head, int data)
{
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));

    temp->data = data;
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

    int newData;
    printf("Enter data for new node: ");
    scanf("%d", &newData);
    add_at_end(head, newData);

    if (head == NULL)
        printf("Empty Node");
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    return 0;
}