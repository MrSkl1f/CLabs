#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

void multiplication(struct matrix_t *res, struct matrix_t matr_first, struct matrix_t matr_second, int size, int *err);
void multiplication_matr(struct matrix_t *res_matr, int **matr_first, int **matr_second, int pow, int *err);
void multiply_once(struct matrix_t *res, struct matrix_t *calc, int **matr_first, int **matr_second);
void input_pows(int *p, int *q, int *err);
void fill_num(struct matrix_t *matrix, int num);
void copy_matrix(struct matrix_t *first, struct matrix_t *second);
void zero_pow_matr(struct matrix_t *matrix);
void check_pow(struct matrix_t *res_matr, struct matrix_t *matr, int pow, int *err);

#endif