#define FALSERES 1
#define TRUERES 0
#define INSERT_INDEX 3

#ifndef ARR_H
#define ARR_H

double second_count(double *array, int count_of_numbers);
void array_insertion(double *array, int count_of_numbers, double result, int position);
int deletion_min_max(double *array, int count, double result);
void shift_min_diff(double *array, int count, int index);
int min_diff(double *array, int count_of_numbers, double result);

#endif
