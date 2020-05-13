#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <windows.h>

#include "array_opeations.h"
#include "universal.h"

int main()
{
    HINSTANCE dlib = LoadLibrary(("libdynamic.dll"));
    void (*DLL_input_array) (double *array, int *flag, int count_of_numbers); // input_array
    double (*DLL_geometric_mean_modules) (double *array, int count_of_numbers); // geometric_mean_modules
    int (*DLL_deletion_min_max) (double *array, int count, double result); // deletion_min_max
    void (*DLL_array_insertion) (double *array, int count_of_numbers, double result, int position); // array_insertion
    void (*DLL_see_out) (double *array, int count_of_numbers); //see_out
    double (*DLL_second_count) (double *array, int count_of_numbers); // second_count
    
    int flag = FALSERES;

    int count_of_numbers;
    if ((scanf("%d", &count_of_numbers) == 1) && (count_of_numbers > 3))
    {
        double *array = malloc(count_of_numbers * sizeof(double));
        if (array)
        {
            DLL_input_array = (void(*) (double *array, int *flag, int count_of_numbers))GetProcAddress(dlib, "input_array");
            DLL_input_array(array, &flag, count_of_numbers);

            if (flag == TRUERES)
            {
                flag = FALSERES;

                // Count geometric mean modules
                DLL_geometric_mean_modules = (double(*)(double *array, int count_of_numbers))GetProcAddress(dlib, "geometric_mean_modules");
                double result_first = DLL_geometric_mean_modules(array, count_of_numbers);

                // Count min different of numbers and count for new array
                DLL_deletion_min_max = (int(*)(double *array, int count, double result))GetProcAddress(dlib, "deletion_min_max");
                count_of_numbers = DLL_deletion_min_max(array, count_of_numbers, result_first);

                // New array
                array = realloc(array, (count_of_numbers) * sizeof(double));
                if (array)
                {
                    int position_in_second_array;
                    if (scanf("%d", &position_in_second_array) == 1 && position_in_second_array >= 0 && position_in_second_array < count_of_numbers)
                    {
                        array = realloc(array, (count_of_numbers * sizeof(double) + INSERT_INDEX * sizeof(double)));
                        if (array)
                        {
                            DLL_array_insertion = (void(*)(double *array, int count_of_numbers, double result, int position))GetProcAddress(dlib, "array_insertion");
                            DLL_second_count = (double(*)(double *array, int count_of_numbers))GetProcAddress(dlib, "second_count");
                            DLL_array_insertion(array, count_of_numbers, DLL_second_count(array, count_of_numbers), position_in_second_array);
                            DLL_see_out = (void(*)(double *array, int count_of_numbers))GetProcAddress(dlib, "see_out");
                            DLL_see_out(array, count_of_numbers + INSERT_INDEX);
                            flag = TRUERES;
                        }
                    }
                }
            }
        }
        free(array);
    }
    FreeLibrary(dlib);
    return flag;
}