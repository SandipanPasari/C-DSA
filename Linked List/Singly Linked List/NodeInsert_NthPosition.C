#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void add_nthnode(struct node *head, int data, int pos)
{
    struct node *ptr = head;
    struct node *ptr2 = (struct node *)malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;

    pos--;
    while (pos != 1)
    {
        ptr = ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
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

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    int newData;
    printf("Enter data for new node: ");
    scanf("%d", &newData);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr;
    ptr = head;
    temp->data = newData;
    temp->link = NULL;

    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;

    int nthnode;
    printf("Enter data for nth node: ");
    scanf("%d", &nthnode);
    int position;
    printf("Enter position: ");
    scanf("%d", &position);

    add_nthnode(head, nthnode, position);

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