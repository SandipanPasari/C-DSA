#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the array : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", &arr[i]);
    }

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + i;
    }

    int avg = 0;

    for (int i = 0; i < n; i++)
    {
        avg = sum / n;
    }
    return 0;
}