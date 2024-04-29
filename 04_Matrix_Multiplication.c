#include <stdio.h>

int main()
{
    int row1, col1, row2, col2, i, j, k;

    // Input the dimensions of the first matrix
    printf("Enter the number of rows for matrix 1: ");
    scanf("%d", &row1);
    printf("Enter the number of columns for matrix 1: ");
    scanf("%d", &col1);

    // Input the dimensions of the second matrix
    printf("Enter the number of rows for matrix 2: ");
    scanf("%d", &row2);
    printf("Enter the number of columns for matrix 2: ");
    scanf("%d", &col2);

    if (col1 != row2)
    {
        printf("Matrix multiplication is not possible. Number of columns in matrix 1 must be equal to the number of rows in matrix 2.\n");
        return 1; // exit with error
    }

    int matrix1[row1][col1], matrix2[row2][col2], result[row1][col2];

    // Input the elements of the first matrix
    printf("Enter elements of matrix 1:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input the elements of the second matrix
    printf("Enter elements of matrix 2:\n");
    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Initialize the result matrix with zeros
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            for (k = 0; k < col1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print the result matrix
    printf("Result of matrix multiplication:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
