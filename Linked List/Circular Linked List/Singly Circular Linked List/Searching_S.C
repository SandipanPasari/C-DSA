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
int search(struct node *tail, int element)
{
    struct node *temp;
    int index = 0;

    if (tail == NULL)
    {
        return -2;
    }
    temp = tail->next;
    do
    {
        if (temp->data == element)
        {
            return index;
        }
        temp = temp->next;
        index++;
    } while (temp != tail);
    return -1;
}
int main()
{
    struct node *tail;
    tail = add_to_empty(45);
    tail = add_at_end(tail, 30);
    tail = add_at_end(tail, 88);
    tail = add_at_end(tail, 20);
    tail = add_at_end(tail, 14);

    struct node *ptr;
    ptr = tail->next;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);

    printf("\n");

    int element;
    printf("Enter the element : ");
    scanf("%d", &element);

    int index = search(tail, element);
    if (index == -1)
        printf("Element not found!!");
    else if (index == -2)
        printf("Linked List is empty!!");
    else
        printf("Element %d is at %d index", element, index);
    return 0;
}