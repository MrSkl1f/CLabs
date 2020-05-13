// Склифасовский Денис ИУ7-25
// Программа, которая вычисляет
// нормальный вес человека и индекс массы

#include <stdio.h>
#include <math.h>

double weight(double h, double t);
double mass_index(double m, double h);

int main(void)
{	
	printf("Input growth in centimeters > ");
	double h;
	scanf("%lf", &h);
	printf("Input chest circumference > ");
	double t; 
	scanf("%lf", &t);
	printf("Input weight > ");
	double m;
	scanf("%lf", &m);
	
	printf("Your normal weight is %.5lf\n", weight(h, t));

	printf("Your mass index is %.5lf", mass_index(m, h));

	return 0;
}

double weight(double h, double t)
{
	return h * t / 240;
}

double mass_index(double m, double h)
{
	return m / pow(h / 100, 2);
}

