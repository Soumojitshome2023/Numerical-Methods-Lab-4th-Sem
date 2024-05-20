#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
	// Function
	return (x * x * x) - 2 * x - 5;
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
			// c = a - (f(a) * (b - a)) / (f(b) - f(a));
			// if (f(c) > 0)
			// 	a = c;
			// else
			// 	b = c;
			// h = a - (f(a) * (b - a)) / (f(b) - f(a));

			// or,

			c = (a * f(b) - b * f(a)) / (f(b) - f(a));
			if (f(c) < 0)
				a = c;
			else
				b = c;
			h = (a * f(b) - b * f(a)) / (f(b) - f(a));


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

/*
Output :
Enter two initial guesses : 2
3
Value of  h : 2.081264
Value of  h : 2.089639
Value of  h : 2.092740
Value of  h : 2.093884
Value of  h : 2.094305
Value of  h : 2.094461
Value of  h : 2.094518
The root is : 2.094518
*/