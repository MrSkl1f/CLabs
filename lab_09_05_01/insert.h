#ifndef INSERT_H
#define INSERT_H

int fit_to_one_size(struct matrix_t *matr_first, struct matrix_t *matr_second, int *err);
int check_max_in_rows(int **matr, int row, int col);
int geometric_mean_modules(int **matr, int size, int col);
int find_more(int first, int second);
void input_num_in_resized_col(int **matr, int row, int col);
void resize_cols_for_insert(int ***matr, int row, int col, int need);
void insert_geo_mean_in_resized_row(int **matr, int row, int col);
void resize_rows_for_insert(int ***matr, int row, int col, int need);
void resize_and_fit_for_insert(int ***matr, int size, int size_last, int *err);

#endif