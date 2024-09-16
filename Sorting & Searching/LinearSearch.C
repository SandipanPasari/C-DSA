#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of elements in the array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int x;
    printf("Enter the element to be searched : ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            printf("%d is found in element number %d\n", x, i);
        }
    }
    return 0;
}