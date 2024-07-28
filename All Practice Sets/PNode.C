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
    printf("Enter Data : ");
    scanf("%d", &head->data);
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &current->data);
    current->link = NULL;
    head->link = current;

    current = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &current->data);
    current->link = NULL;
    head->link->link = current;

    if (head == NULL)
    {
        printf("Empty Node");
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    return 0;
}