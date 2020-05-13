#include <stdio.h>
#include <malloc.h>
#include <math.h>

#include "array_opeations.h"
#include "universal.h"

int main()
{
    int flag = FALSERES;

    int count_of_numbers;
    if ((scanf("%d", &count_of_numbers) == 1) && (count_of_numbers > 3))
    {
        double *array = malloc(count_of_numbers * sizeof(double));
        if (array)
        {
            input_array(array, &flag, count_of_numbers);

            if (flag == TRUERES)
            {
                flag = FALSERES;

                // Count geometric mean modules
                double result_first = geometric_mean_modules(array, count_of_numbers);

                // Count min different of numbers and count for new array
                count_of_numbers = deletion_min_max(array, count_of_numbers, result_first);

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
                            array_insertion(array, count_of_numbers, second_count(array, count_of_numbers), position_in_second_array);
                            see_out(array, count_of_numbers + INSERT_INDEX);
                            flag = TRUERES;
                        }
                    }
                }
            }
        }
        free(array);
    }
    return flag;
}

