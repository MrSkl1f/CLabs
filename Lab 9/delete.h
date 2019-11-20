#ifndef DELETE_H
#define DELETE_H

int transformation(struct matrix_t *matrix);
void delete_rows(struct matrix_t *matrix);
void find_index(struct matrix_t matrix, int *index, int flag);
void delete_row_by_index(int ***matr, int index, int n);
void delete_cols(struct matrix_t *matrix);
void delete_col_by_index(struct matrix_t *matrix, int index);
void resize_cols_for_delete(struct matrix_t *matrix);

#endif