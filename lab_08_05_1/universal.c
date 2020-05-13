#include <stdio.h>
#include <math.h>
#include "array_opeations.h"
#include "universal.h"

void input_array(double *array, int *flag, int count_of_numbers)
{
    *flag = TRUE;
    for (int i = 0; i < count_of_numbers; i++)
        if (scanf("%lf", (array + i)) != 1)
            *flag = FALSE;
}

void see_out(double *array, int count_of_numbers)
{
    for (int i = 0; i < count_of_numbers; i++)
        printf("%.6lf ", *(array + i));
    printf("\n");
}

double find_elem(double *array, int count_of_numbers, int (*operations)(double, double))
{
    double elem = *(array);
    for (int i = 0; i < count_of_numbers; i++)
        if (operations(*(array + i), elem))
            elem = *(array + i);
    return elem;
}

int get_max(double first, double second)
{
    return first > second;
}

int get_min(double first, double second)
{
    return first < second;
}

void insert_in_place(double *array, int count_of_numbers, int need_position, double result)
{
    for (int i = count_of_numbers - 1; i > need_position; --i)
        *(array + i) = *(array + i - 1);
    *(array + need_position) = result;
}

double geometric_mean_modules(double *array, int count_of_numbers)
{
    double result = 1;
    for (int i = 0; i < count_of_numbers; i++)
        result *= fabs(*(array + i));
    result = pow(result, 1. / count_of_numbers);
    return result;
}