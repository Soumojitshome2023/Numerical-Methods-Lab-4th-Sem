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

/*==============================================
#define f(x) (x*x*x - x - 4)

void main(){
	float x0, x1, x2, f0, f1, f2, e;
	int step = 1;

	up:
	 printf("Enter two initial guesses : ");
	 scanf("%f%f", &x0, &x1);
	 f0 = f(x0);
	 f1 = f(x1);
	 if(f0*f1 > 0.0){
		printf("Incorrect initial guesses");
		goto up;
	 }
	 printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
	 do{
		x2 = (x0 + x1)/2;
		f2 = f(x2);

		printf("%d\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);
		if(f0*f2<0){
			x1 = x2;
			f1= f1;
		}
		else{
			x0 = x2;
			f0 = f2;
		}
		step = step + 1;
	 }while(fabs(f2)>2);
	 printf("Root if : %f", x2);

}
*/
