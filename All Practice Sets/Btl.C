#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *createTree();

int main()
{
    struct node *root = createTree();
    printf("%d ", root->data);
    printf("%d ", root->left->data);
    printf("%d ", root->right->data);
    printf("%d ", root->left->left->data);
    return 0;
}
struct node *createTree()
{
    int input, data;
    printf("Do you want to add a node ? (0 = > No and 1 = > Yes) : ");
    scanf("%d", &input);
    if (!input)
    {
        return NULL;
    }
    else 
    {
        
    }
}