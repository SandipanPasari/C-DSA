#include <stdio.h>
void insertion(int n, int arr[])
{
    printf("\nUnsorted Array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the elements of array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertion(n, arr);
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}