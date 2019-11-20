#include "base.h"

void matrix_calculation(struct matrix_t *matrix, int *err)
{
    input_size_matrix(&(matrix->row), &(matrix->col), err);
    if (!*err)
    {  
        create_matrix(matrix);
        if (&(matrix->matr))
        {
            input_matrix(matrix, err);
            if (*err)
                delete_matrix(matrix);
        }
        else
            *err = ERROR;
    }
}

void create_matrix(struct matrix_t *matrix)
{
    matrix->matr = (int **)malloc(matrix->row * sizeof(int *));
    if (matrix->matr)
        for (int i = 0; i < matrix->row; i++)
            (matrix->matr)[i] = (int *)malloc(matrix->col * sizeof(int));
}

void delete_matrix(struct matrix_t *matrix)
{
    for (int i = 0; i < matrix->row; i++)
        free((matrix->matr)[i]);
    free(matrix->matr);
    matrix->matr = NULL;
}

void input_matrix(struct matrix_t *matrix, int *err)
{
    *err = OK;
    for (int i = 0; i < matrix->row; i++)
        for (int j = 0; j < matrix->col; j++)
            if (!*err && scanf("%d", (*(matrix->matr + i) + j)) != 1)
                *err = ERROR;
}

void input_size_matrix(int *n, int *m, int *err)
{
    *err = ERROR;
    if (scanf("%d", n) == 1)
        if (scanf("%d", m) == 1)
            if (*n > 1 && *m > 1)
                *err = OK;
}

void see_out_matrix(struct matrix_t matrix)
{
    for (int i = 0; i < matrix.row; i++)
    {
        for (int j = 0; j < matrix.col; j++)
            printf("%d ", *(*(matrix.matr + i) + j));
        printf("\n");
    }
}

void fill_matrix(struct matrix_t *matrix)
{
    for (int i = 0; i < matrix->row; i++)
        for (int j = 0; j < matrix->col; j++)
            *(*(matrix->matr + i) + j) = 0;
}