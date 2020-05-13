#ifndef UNI_H
#define UNI_H

void input_array(double *array, int *flag, int count_of_numbers);
double geometric_mean_modules(double *array, int count_of_numbers);
double find_elem(double *array, int count_of_numbers, int (*operations)(double, double));
int get_min(double first, double second);
int get_max(double first, double second);
void insert_in_place(double *array, int count_of_numbers, int need_position, double result);
void see_out(double *array, int count_of_numbers);

#endif