#include <stdio.h>

// calculating u mentioned in the formula
float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u + i);
    return temp;
}

// calculating factorial of given number n
int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

int main()
{
    int n; // Number of values given
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    float x[n], y[n][n];

    printf("Enter the x values:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("Enter the corresponding y values:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &y[i][0]);

    // Calculating the backward difference table
    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    }

    // Displaying the backward difference table
    printf("Backward Difference Table:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f\t", x[i]);
        for (int j = 0; j <= i; j++)
            printf("%.6f\t", y[i][j]);
        printf("\n");
    }

    // Value to interpolate at
    float value;
    printf("\nEnter the value at which you want to interpolate: ");
    scanf("%f", &value);

    // initializing u and sum
    float sum = y[n - 1][0];
    float u = (value - x[n - 1]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++)
    {
        sum = sum + (u_cal(u, i) * y[n - 1][i]) / fact(i);
    }

    printf("Interpolated value at %.2f is %.6f\n", value, sum);
    return 0;
}