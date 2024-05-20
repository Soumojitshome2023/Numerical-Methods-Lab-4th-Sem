#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
	// Function
	return (x * x * x) - x - 1;
}
double Bisection(double a, double b)
{
	double c, h;
	if (f(a) * f(b) > 0)
		exit(0);
	else
	{
		do
		{
			c = (a + b) / 2;
			if (f(c) < 0)
				a = c;
			else
				b = c;
			h = (a + b) / 2;
			printf("Value of  h : %f\n", h);
		} while (fabs(h - c) > 0.0001);
	}
	return h;
}
int main()
{
	float x0, x1;
	printf("Enter two initial guesses : ");
	scanf("%f%f", &x0, &x1);
	double root = Bisection(x0, x1);
	printf("The root is : %f\n", root);
	return 0;
}

/*
Output :
Enter two initial guesses : 1
2
Value of  h : 1.250000
Value of  h : 1.375000
Value of  h : 1.312500
Value of  h : 1.343750
Value of  h : 1.328125
Value of  h : 1.320313
Value of  h : 1.324219
Value of  h : 1.326172
Value of  h : 1.325195
Value of  h : 1.324707
Value of  h : 1.324951
Value of  h : 1.324829
Value of  h : 1.324768
The root is : 1.324768
*/