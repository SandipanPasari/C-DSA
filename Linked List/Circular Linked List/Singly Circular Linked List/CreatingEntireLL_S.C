#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *add_to_empty(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

struct node *add_at_end(struct node *tail, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    temp->next = tail->next;
    tail->next = temp;
    tail = tail->next;
    return tail;
}
struct node *createList(struct node *tail)
{
    int i, n, data;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);

    if (n == 0)
    {
        return tail;
    }
    printf("Enter the element 1 : ");
    scanf("%d", &data);
    tail = add_to_empty(data);

    for (int i = 1; i < n; i++)
    {
        printf("Enter the element %d : ", i + 1);
        scanf("%d", &data);
        tail = add_at_end(tail, data);
    }
    return tail;
}
int main()
{
    struct node *tail;
    tail = createList(tail);
    struct node *ptr;
    ptr = tail->next;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);

    return 0;
}
