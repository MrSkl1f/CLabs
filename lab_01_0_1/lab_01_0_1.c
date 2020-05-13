// Склифасовский Денис ИУ7-25
// Программа, которая вычисляет периметор 
// равнобедренной трапеции по введенным высоте и основаниям

#include <stdio.h>
#include <math.h>
double perimeter(double a, double b, double h);

int main(void)
{
	double a, b, h;	// Данные, которые вводим с клавиатуры
	printf("Input a > ");
	scanf("%lf", &a);
	printf("Input b > ");
	scanf("%lf", &b);
	printf("Input h > ");
	scanf("%lf", &h);

	printf("P = %.5lf", perimeter(a, b, h));

	return 0;
}

double perimeter(double a, double b, double h)
{
	double c;
	if (b > a)
	{
		c = (b - a) / 2;	
	}
	else
	{
		c = (a - b) / 2;
	}
	double d = sqrt(pow(c, 2) + pow(h, 2));
	double p = a + b + 2 * d;
	return p;
}