#include <stdio.h>
void towerOfHanoi(int n, char from, char to, char rod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        return;
    }
    towerOfHanoi(n - 1, from, rod, rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from, to);
    towerOfHanoi(n - 1, rod, to, from);
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}