#include <stdio.h>
int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    int n = 5;
    printf("Unshorted Array \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int min = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    printf("\n");
    printf("Shorted Array \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}