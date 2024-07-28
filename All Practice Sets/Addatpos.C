#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *add_nthnode(struct node *head, int data, int position)
{
    struct node *ptr = head;
    struct node *ptr2 = (struct node *)malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;

    position--;
    while (position != 1)
    {
        ptr = ptr->link;
        position--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
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
    printf("Enter Data : ");
    scanf("%d", &current->data);
    current->link = NULL;
    head->link->link = current;

    int nthnode;
    printf("Enter data for nth node: ");
    scanf("%d", &nthnode);
    int position;
    printf("Enter position: ");
    scanf("%d", &position);

    head = add_nthnode(head, nthnode, position);
    if (head == NULL)
    {
        printf("Empty Node ");
    }
    struct node *p = NULL;
    p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->link;
    }
    return 0;
}