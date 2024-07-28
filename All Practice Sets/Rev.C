#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *reverse(struct node *head)
{
    struct node *previous = NULL;
    struct node *next = NULL;
    while (head != NULL)
    {
        next = head->link;
        head->link = previous;
        previous = head;
        head = next;
    }
    head = previous;
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

    current = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &current->data);
    current->link = NULL;
    head->link->link->link = current;

    head = reverse(head);

    if (head == NULL)
    {
        printf("Empty node !!");
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