#include <stdio.h>
#include <math.h>

double main_function(double x);
double accurate_function(double x, double eps);
double absolute_error(double x, double eps);
double relative_error(double x, double eps);

int main()
{
	double x, eps;
	int rc, check;
	printf("Input your x and epsilon > ");
	rc = scanf("%lf %lf", &x, &eps);

	if (rc == 2 && eps > 0 && eps < 1)
	{
		printf("f(x) = %lf\n", main_function(x));
		printf("s(x) = %lf\n", accurate_function(x, eps));
		printf("Absolute error: %.5lf\n", absolute_error(x, eps));
		printf("Relative error: %.5lf\n", relative_error(x, eps));
		check = 0;
	}
	else
	{
		printf("Error!\n");
		check = 1;
	}
	return check;
}

double main_function(double x)
{
	return exp(x);
}

double accurate_function(double x, double eps)
{
	double result = 0;
	double current = 1;
	int counter = 1;

	while (fabs(current) > eps)
	{
		result += current;
		current *= x / counter;
		counter++;
	}
	return result;
}

double absolute_error(double x, double eps)
{
	return fabs(main_function(x) - accurate_function(x, eps));
}

double relative_error(double x, double eps)
{
	return fabs((main_function(x) - accurate_function(x, eps)) / (main_function(x)));
}
