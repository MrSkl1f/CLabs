#include <stdio.h>
#include <malloc.h>
#include "array_opeations.h"
#include "universal.h"

void check_geometric_mean_modules();
void check_find_elem();
void check_get_min();
void check_get_max();
void check_second_count();
void check_insert_in_place();
void check_see_out();
void check_array_insertion();
void check_delete_min_max();
void check_shift_min_diff();
void check_min_diff();


int main()
{
    check_geometric_mean_modules();
    check_find_elem();
    check_get_min();
    check_get_max();
    check_second_count();
    check_insert_in_place();
    check_see_out();
    check_array_insertion();
    check_delete_min_max();
    check_shift_min_diff();
    check_min_diff();

    return 0;
}

void check_geometric_mean_modules()
{
    double array[4] = { 2, 2, 2, 2 };
    int count = 4;
    if (geometric_mean_modules(array, count) == 2.)
        printf("Geometric mean modules correct\n");
}

void check_find_elem()
{
    double array[4] = { 1., 2., 3., 4. };
    if (find_elem(array, 4, get_min) == 1.)
        printf("Correct work find min\n");
    if (find_elem(array, 4, get_max) == 4.)
        printf("Correct work find get max\n");
}

void check_get_min()
{
    if (!get_min(5., 4.))
        printf("Correct work get min err\n");
    if (get_min(4., 5.))
        printf("Correct work get min correct\n");    
}

void check_get_max()
{
    if (get_max(5., 4.))
        printf("Correct work get max correct\n");
    if (!get_max(4., 5.))
        printf("Correct work get max err\n"); 
}

void check_second_count()
{
    double array[5] = { 10., 4., 1., 11., 0. };
    if (second_count(array, 5) == 0.)
        printf("Correct work of second count\n");
}

void check_insert_in_place()
{
    double array[4] = { 5., 5., 5., 0. };
    double check_array[4] = { 5., 1., 5., 5. };
    insert_in_place(array, 4, 1, 1.);
    for (int i = 0; i < 4; i++)
        if (array[i] != check_array[i])
            printf("Not correct\n");
    printf("Correct check ins in place\n");
}

void check_see_out()
{
    double array[4] = { 1., 2., 3., 4. };
    see_out(array, 4);
}

void check_array_insertion()
{
    double array[5] = { 5., 5., 0., 0., 0. };
    double check_array[5] = { 1., 5., 1., 5., 1. };
    array_insertion(array, 2, 1., 1);
    for (int i = 0; i < 5; i++)
        if (array[i] != check_array[i])
            printf("Not correct\n");
    printf("Correct check ins\n");
}

void check_delete_min_max()
{
    double array[3] = { 100., 0.5, 0. };
    double check_array = 100.;
    deletion_min_max(array, 3, 5.);
    if (array[0] == check_array)
        printf("Correct work of delete\n");
}

void check_shift_min_diff()
{
    double array[4] = { 100., 0.5, 1., 0. };
    double check_array[4] = { 100., 1., 0., 0. };
    shift_min_diff(array, 4, 1);
    for (int i = 0; i < 4; i++)
        if (array[i] != check_array[i])
            printf("Not correct\n");
    printf("Correct check shift min diff\n");
}

void check_min_diff()
{
    double array[5] = { 10., 4., 1., 11., 0. };
    int ind = 1;
    if (min_diff(array, 5, 3.9) == ind)
        printf("Correct work of min diff\n");
}
