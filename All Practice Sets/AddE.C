#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *add_node_end(struct node *head, int newData)
{
    struct node *ptr;
    ptr = head;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = newData;
    temp->link = NULL;
    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
    return head;
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

    head = add_node_end(head, newData);
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