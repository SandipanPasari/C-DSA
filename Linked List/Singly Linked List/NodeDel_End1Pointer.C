#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void del_last(struct node *head)
{
    if (head == NULL)
    {
        free(head);   
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->link->link != NULL)
        {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
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

    del_last(head);

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