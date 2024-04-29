#include <stdio.h>

// calculating u mentioned in the formula
float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u - i);
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

    // Calculating the forward difference table
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
    }

    // Displaying the forward difference table
    printf("Forward Difference Table:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f\t", x[i]);
        for (int j = 0; j < n - i; j++)
            printf("%.6f\t", y[i][j]);
        printf("\n");
    }

    // Value to interpolate at
    float value;
    printf("\nEnter the value at which you want to interpolate: ");
    scanf("%f", &value);

    // initializing u and sum
    float sum = y[0][0];
    float u = (value - x[0]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++)
    {
        sum = sum + (u_cal(u, i) * y[0][i]) / fact(i);
    }

    printf("Interpolated value at %.2f is %.6f\n", value, sum);
    return 0;
}
