#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
	// Function
	return x * x * x - 9 * x + 1;
}
double RegulaFalsi(double a, double b)
{
	double c, h;
	if (f(a) * f(b) > 0)
		exit(0);
	else
	{
		do
		{
			c = a - (f(a) * (b - a)) / (f(b) - f(a));
			if (f(c) > 0)
				a = c;
			else
				b = c;
			h = a - (f(a) * (b - a)) / (f(b) - f(a));
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
	double root = RegulaFalsi(x0, x1);
	printf("The root is : %f\n", root);
	return 0;
}
