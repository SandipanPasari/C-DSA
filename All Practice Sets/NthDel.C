#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *del_pos(struct node *head, int position)
{
    struct node *current = head;
    struct node *previous = head;
    if (position == 1)
    {
        head = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while (position != 1)
        {
            previous = current;
            current = current->link;
            position--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
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

    int pos;
    printf("Enter Position : ");
    scanf("%d", &pos);
    head = del_pos(head, pos);

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