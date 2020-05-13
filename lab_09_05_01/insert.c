/*
Добавлять всегда сначала новые строки, потом — столбцы.
Добавлять в новые строки округлённые к нижнему целому средние геометрические модулей элементов
столбцов
Добавлять в новые столбцы максимумы по строкам
*/
#include "base.h"
#include <math.h>

int fit_to_one_size(struct matrix_t *matr_first, struct matrix_t *matr_second, int *err)
{
    int size = find_more(matr_first->row, matr_second->row);
    if (matr_first->row > matr_second->row)
    {
        resize_and_fit_for_insert(&(matr_second->matr), size, matr_second->row, err);
        if (*err)
            *err = FIRST;
    }
    else if (matr_first->row < matr_second->row)
    {
        resize_and_fit_for_insert(&(matr_first->matr), size, matr_first->row, err);
        if (*err)
            *err = SECOND;
    }
    return size;
}

void resize_and_fit_for_insert(int ***matr, int size, int size_last, int *err)
{
    int row = size_last, col = size_last;
    resize_rows_for_insert(matr, row, col, size - size_last);
    if (matr)
    {
        for (; row != size; row++)
            insert_geo_mean_in_resized_row(*matr, row, col);
        resize_cols_for_insert(matr, row, col, size - size_last);
        if (matr)
        {
            for (; col != size; col++)
                input_num_in_resized_col(*matr, row, col);
        }
        else
            *err = ERROR;
    }
    else
        *err = ERROR;
}

void input_num_in_resized_col(int **matr, int row, int col)
{
    for (int i = 0; i < row; i++)
        *(*(matr + i) + col) = check_max_in_rows(matr, i, col - 1);
}

void resize_cols_for_insert(int ***matr, int row, int col, int need)
{
    for (int i = 0; i < row; i++)
        (*matr)[i] = (int *)realloc((*matr)[i], col * sizeof(int) + need * sizeof(int));
} 

void insert_geo_mean_in_resized_row(int **matr, int row, int col)
{
    for (int j = 0; j < col; j++)
        *(*(matr + row) + j) = geometric_mean_modules(matr, row, j);
}

void resize_rows_for_insert(int ***matr, int row, int col, int need)
{
    int new_row = row + need;
    *matr = (int **)realloc(*matr, new_row * sizeof(int *));
    for (int i = row; i < new_row; i++)
        (*matr)[i] = (int *)malloc(col * sizeof(int));
}

int check_max_in_rows(int **matr, int row, int col)
{
    int check = *(*(matr + row));
    for (int i = 0; i < col + 1; i++)
        if (*(*(matr + row) + i) > check)
            check = *(*(matr + row) + i);
    return check;
}

int geometric_mean_modules(int **matr, int size, int col)
{
    double check = 1;
    for (int i = 0; i < size; i++)
        check *= (*(*(matr + i) + col));
    return (int)(floor(pow(check, 1. / size)));
}

int find_more(int first, int second)
{
    int check;
    if (first > second)
        check = first;
    else
        check = second;
    return check;
}