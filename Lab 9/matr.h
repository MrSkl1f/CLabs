#ifndef MATR_H
#define MATR_H

void matrix_calculation(struct matrix_t *matrix, int *err);
void input_size_matrix(int *n, int *m, int *err);
void delete_matrix(struct matrix_t *matrix);
void create_matrix(struct matrix_t *matrix);
void input_numbers_matrix(int **matrix, int row, int col, int *err);
void see_out_matrix(struct matrix_t matrix);
void input_matrix(struct matrix_t *matr, int *err);
void fill_matrix(struct matrix_t *matrix);

#endif