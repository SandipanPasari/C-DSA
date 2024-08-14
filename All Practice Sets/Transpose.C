#include <stdio.h>
int main()
{
    int n, m;
    printf("Enter rows : ");
    scanf("%d", &n);
    printf("Enter coloumns : ");
    scanf("%d", &m);
    int arr[n][m];
    printf("Enter the matrix : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The matrix is : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    printf("Transpose is : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr[j][i]);
           
        }
        printf("\n");
    }
    return 0;
}