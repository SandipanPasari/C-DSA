#include <stdio.h>

// Recursive function to compute the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n = 9; // Change this to the desired number of terms
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    return 0;
}
