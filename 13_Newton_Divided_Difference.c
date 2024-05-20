#include <stdio.h>

// Function to calculate the divided differences table
void dividedDifferenceTable(double x[], double y[][10], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = (y[j + 1][i - 1] - y[j][i - 1]) / (x[j + i] - x[j]);
        }
    }
}

// Function to apply Newton's divided difference formula
double applyFormula(double x[], double y[][10], double value, int n)
{
    double result = y[0][0]; // Initial value of result

    for (int i = 1; i < n; i++)
    {
        double term = y[0][i];
        for (int j = 0; j < i; j++)
        {
            term *= (value - x[j]);
        }
        result += term;
    }

    return result;
}

// Function to print the divided difference table
void printDividedDifferenceTable(double y[][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf("%lf ", y[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n][10];

    // Reading the data points
    printf("Enter the x and y values:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d]: ", i);
        scanf("%lf", &x[i]);
        printf("y[%d]: ", i);
        scanf("%lf", &y[i][0]);
    }

    // Calculate the divided difference table
    dividedDifferenceTable(x, y, n);

    // Display the divided difference table
    printf("Divided Difference Table:\n");
    printDividedDifferenceTable(y, n);

    // Get the interpolation point
    double value;
    printf("Enter the value to interpolate at: ");
    scanf("%lf", &value);

    // Apply the formula to get the result
    double result = applyFormula(x, y, value, n);
    printf("Interpolated value at %.2lf is %.2lf\n", value, result);

    return 0;
}


/*
Output :
Enter the number of data points: 4
Enter the x and y values:
x[0]: 5
y[0]: 12
x[1]: 6
y[1]: 13
x[2]: 9
y[2]: 14
x[3]: 11
y[3]: 16
Divided Difference Table:
12.000000 1.000000 -0.166667 0.050000 
13.000000 0.333333 0.133333 
14.000000 1.000000
16.000000
Enter the value to interpolate at: 10
Interpolated value at 10.00 is 14.67

*/