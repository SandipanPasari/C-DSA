#include <stdio.h>

int main() {
    int arr[5] = {1, 7, 47, 10, 2};
    int n, i;
    int got = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 0; i < 5; i++) {
        if (arr[i] == n) {
            got = 1;
            break;
        }
    }

    if (got) {
        printf("%d is found at index %d.\n", n, i);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}
