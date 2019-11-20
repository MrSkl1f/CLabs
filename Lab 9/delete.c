/*
    Удаление
    Удалять строки или столбцы с минимальным элементом матрицы
    Если обнаружено несколько, считать целевым минимум, который был бы встречен 
    при обходе по строкам
*/

#include "base.h"

int transformation(struct matrix_t *matrix)
{
    int size;
    if (matrix->row > matrix->col)
    {
        delete_rows(matrix);
        size = matrix->col;
    }
    else if (matrix->col > matrix->row)
    {
        delete_cols(matrix);
        resize_cols_for_delete(matrix);
        size = matrix->row;
    }
    else
        size = matrix->row;
    return size;
}

void delete_rows(struct matrix_t *matrix)
{ 
    int index = 0;
    for (; matrix->row - matrix->col != 0; (matrix->row)--)
    {
        find_index(*matrix, &index, 0);
        delete_row_by_index(&(matrix->matr), index, matrix->row);
    }
}

void find_index(struct matrix_t matrix, int *index, int flag)
{
    int min_elem = **(matrix.matr);
    for (int i = 0; i < matrix.row; i++)
    {
        for (int j = 0; j < matrix.col; j++)
        {
            if (*(*(matrix.matr + i) + j) < min_elem)
            {
                if (flag)
                    *index = j;
                else if (!flag)
                    *index = i;
                min_elem = *(*(matrix.matr + i) + j);
            }
        }
    }
}

void delete_row_by_index(int ***matr, int index, int n)
{
    free((*matr)[index]);
    for (int i = index; i < n - 1; i++)
        (*matr)[i] = (*matr)[i + 1];
}

void delete_cols(struct matrix_t *matrix)
{
    int index = 0;
    for (; matrix->col - matrix->row != 0; (matrix->col)--)
    {
        find_index(*matrix, &index, 1);
        delete_col_by_index(matrix, index);
    }
}

void delete_col_by_index(struct matrix_t *matrix, int index)
{
    for (int i = 0; i < matrix->row; i++)
        for (int j = index; j < matrix->col - 1; j++)
            *(*(matrix->matr + i) + j) = *(*(matrix->matr + i) + j + 1);
}

void resize_cols_for_delete(struct matrix_t *matrix)
{
    for (int i = 0; i < matrix->row; i++)
        ((matrix->matr))[i] = (int *)realloc(((matrix->matr))[i], matrix->col * sizeof(int));
}
