#include "base.h"

void multiplication(struct matrix_t *res, struct matrix_t matr_first, struct matrix_t matr_second, int size, int *err)
{
    int p = 0, q = 0;
    input_pows(&p, &q, err);
    

    struct matrix_t res_first, res_second;
    res_first.matr = NULL; res_first.row = size; res_first.col = size; 
    res_second.matr = NULL; res_second.row = size; res_second.col = size;
    
    create_matrix(&res_first);
    if (res_first.matr)
    {
        check_pow(&res_first, &matr_first, p, err);

        if (!*err)    
            create_matrix(&res_second);
        
        if (res_second.matr && !*err)
        {
            check_pow(&res_second, &matr_second, q, err);

            if (!*err)
                multiplication_matr(res, res_first.matr, res_second.matr, 2, err);
            
            delete_matrix(&res_first);
            delete_matrix(&res_second);
        }
        else
        {
            *err = ERROR;
            delete_matrix(&res_first);
        }
    }
    else
        *err = ERROR;
}

void check_pow(struct matrix_t *res_matr, struct matrix_t *matr, int pow, int *err)
{
    if (pow > 1)
        multiplication_matr(res_matr, matr->matr, matr->matr, pow, err);
    else if (pow == 1)
        copy_matrix(res_matr, matr);
    else if (pow == 0)
        zero_pow_matr(res_matr);
    else
        *err = ERROR;
}
void zero_pow_matr(struct matrix_t *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->col; j++)
        {
            if (i == j)
                *(*(matrix->matr + i) + j) = 1;
            else
                *(*(matrix->matr + i) + j) = 0;
        }
    }       
}

void multiplication_matr(struct matrix_t *res_matr, int **matr_first, int **matr_second, int pow, int *err)
{
    if (pow == 0)
        fill_num(res_matr, 1);
    else
    {
        struct matrix_t calc_matr; 
        calc_matr.matr = NULL; calc_matr.row = res_matr->row; calc_matr.col = res_matr->col;
        create_matrix(&calc_matr);
        if (calc_matr.matr)
        {
            multiply_once(res_matr, &calc_matr, matr_first, matr_second);
            for (int i = 1; i < pow - 1; i++)
                multiply_once(res_matr, &calc_matr, res_matr->matr, matr_second);
        }
        delete_matrix(&calc_matr);
    }
}

void multiply_once(struct matrix_t *res, struct matrix_t *calc, int **matr_first, int **matr_second)
{
    fill_num(calc, 0);
    for (int i = 0; i < res->row; i++)
        for (int j = 0; j < res->col; j++)
            for (int k = 0; k < res->row; k++)
                *(*(calc->matr + i) + j) += *(*(matr_first + i) + k) * *(*(matr_second + k) + j);
    copy_matrix(res, calc);
}



void fill_num(struct matrix_t *matrix, int num)
{
    for (int i = 0; i < matrix->row; i++)
        for (int j = 0; j < matrix->col; j++)
            *(*(matrix->matr + i) + j) = num;
}

void copy_matrix(struct matrix_t *first, struct matrix_t *second)
{
    for (int i = 0; i < first->row; i++)
        for (int j = 0; j < first->col; j++)
            *(*(first->matr + i) + j) = *(*(second->matr + i) + j);
}

void input_pows(int *p, int *q, int *err)
{
    *err = ERROR;
    if (scanf("%d", p) == 1)
        if (scanf("%d", q) == 1)
            *err = OK;       
}