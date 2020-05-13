#include <stdio.h>
#include <math.h>

// Находит скалярное произведение (для наждения угла)
double scal(double x_1, double y_1, double x_2, double y_2, double x_3, double y_3);
// Функция для нахождения скалярного произведения
double scal_count(double f, double s, double t, double fo);
// Проверка на существование треугольника
double check(double x_1, double y_1, double x_2, double y_2, double x_3, double y_3);

int main()
{
	double x_1, y_1, x_2, y_2, x_3, y_3;
	int rc;
	int out;
	printf("Enter coordinates >  ");
	rc = scanf("%lf %lf %lf %lf %lf %lf", &x_1, &y_1, &x_2, &y_2, &x_3, &y_3);
	if (rc == 6 && check(x_1, y_1, x_2, y_2, x_3, y_3) != 0.0)
	{
		out = 0;
		double scal_count = scal(x_1, y_1, x_2, y_2, x_3, y_3);
		if (scal_count < 0.0)
			printf("0\n");
		else if (scal_count == 0.0)
			printf("1\n");
		else
			printf("2\n");
	}
	else
		out = 1;
	return out;
}

double scal(double x_1, double y_1, double x_2, double y_2, double x_3, double y_3)
{
	double a = scal_count((x_2 - x_1), (x_3 - x_1), (y_2 - y_1), (y_3 - y_1));
	double b = scal_count((x_3 - x_1), (x_3 - x_2), (y_3 - y_1), (y_3 - y_2));
	double c = scal_count((x_2 - x_1), (x_3 - x_2), (y_2 - y_1), (y_3 - y_2));

	return (a * b * c);
}

double scal_count(double f, double s, double t, double fo)
{
	return f * s + t * fo;
}

double check(double x_1, double y_1, double x_2, double y_2, double x_3, double y_3)
{
	return ((x_1 - x_3) * (y_2 - y_3) - (x_2 - x_3) * (y_1 - y_3));
}
