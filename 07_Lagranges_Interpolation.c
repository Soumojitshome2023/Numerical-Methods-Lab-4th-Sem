#include <stdio.h>

int main()
{
    float x[100], y[100], xp, yp = 0, p;
    int i, j, n;

    /* Input Section */
    printf("Enter number of data: ");
    scanf("%d", &n);
    printf("Enter data:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }
    printf("Enter interpolation point: ");
    scanf("%f", &xp);

    /* Implementing Lagrange Interpolation */
    for (i = 1; i <= n; i++)
    {
        p = 1;
        for (j = 1; j <= n; j++)
        {
            if (i != j)
            {
                p = p * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp = yp + p * y[i];
    }

    printf("Interpolated value at %.3f is %.3f.\n", xp, yp);
    return 0;
}

/*
Output :
Enter number of data: 4
Enter data:
x[1] = 5
y[1] = 12
x[2] = 6
y[2] = 13
x[3] = 9
y[3] = 14
x[4] = 11
y[4] = 16
Enter interpolation point: 10
Interpolated value at 10.000 is 14.667.

*/