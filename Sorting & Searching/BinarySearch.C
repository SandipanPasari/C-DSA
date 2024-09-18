#include <stdio.h>

int binarySearch(int array[], int size, int target)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (array[mid] == target)
            return mid; // Target found
        if (array[mid] < target)
            low = mid + 1; // Search the right half
        else
            high = mid - 1; // Search the left half
    }
    return -1; // Target not found
}

int main()
{
    int array[] = {2, 3, 4, 10, 40};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 10;
    int result = binarySearch(array, size, target);
    if (result != -1)
        printf("Element is present at index %d\n", result);
    else
        printf("Element is not present in array\n");
    return 0;
}
