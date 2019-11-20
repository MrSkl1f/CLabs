#include <stdio.h>
#include <math.h>
#include "array_opeations.h"
#include "universal.h"

double second_count(double *array, int count_of_numbers)
{
    double max = find_elem(array, count_of_numbers, get_max);
    double min = find_elem(array, count_of_numbers, get_min);
    return (min * max) / (1 + fabs(min) + fabs(max));
}

void array_insertion(double *array, int count_of_numbers, double result, int position)
{
    insert_in_place(array, count_of_numbers + 1, position, result);
    insert_in_place(array, count_of_numbers + 2, 0, result);
    insert_in_place(array, count_of_numbers + 3, count_of_numbers + 2, result);
}

int deletion_min_max(double *array, int count, double result)
{
    int index = min_diff(array, count, result);
    shift_min_diff(array, count, index);
    index = min_diff(array, count - 1, result);
    shift_min_diff(array, count - 1, index);
    return (count - 2);
}        

int min_diff(double *array, int count_of_numbers, double result)
{
    int j = 0;
    for (int i = 1; i < count_of_numbers; i++)
        if (fabs(*(array + i) - result) < fabs(*(array + j) - result))
            j = i;
    return j;
}

void shift_min_diff(double *array, int count, int index)
{
    for (int i = index; i < count - 1; ++i)
        *(array + i) = *(array + i + 1);
}