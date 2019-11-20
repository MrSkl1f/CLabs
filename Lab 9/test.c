#include "base.h"

void check_create_delete_matrix();
void check_see_out_fill_matrix();
void check_int_transformation();
void check_fit_to_one_size();


int main()
{
    check_create_delete_matrix();
    
    check_see_out_fill_matrix();
    
    check_int_transformation();
    check_fit_to_one_size();

    return 0;
}

void check_create_delete_matrix()
{
    struct matrix_t matrix;
    matrix.matr = NULL; matrix.row = 2, matrix.col = 2;
    create_matrix(&matrix);
    if (matrix.matr)
        printf("Check create yes\n");
    delete_matrix(&matrix);
    if (matrix.matr == NULL)
        printf("Deleted!\n");
}

void check_see_out_fill_matrix()
{
    struct matrix_t matrix;
    matrix.matr = NULL; matrix.row = 2, matrix.col = 2;
    create_matrix(&matrix);
    if (matrix.matr)
    {
        fill_matrix(&matrix);
        see_out_matrix(matrix);
    }
    delete_matrix(&matrix);
}

void check_int_transformation()
{
    struct matrix_t matr_first;
    matr_first.matr = NULL; matr_first.row = 3; matr_first.col = 2;
    struct matrix_t matr_second;
    matr_second.matr = NULL; matr_second.row = 2; matr_second.col = 3;

    create_matrix(&matr_first);
    create_matrix(&matr_second);
    fill_matrix(&matr_first); 
    fill_matrix(&matr_second); 
    int s = transformation(&matr_first);
    int k = transformation(&matr_second);

    if (matr_first.matr && matr_second.matr && k == s)
        printf("Correct transform\n");
    matr_first.row = 2;
    matr_second.col = 2;
    delete_matrix(&matr_first);
    delete_matrix(&matr_second);
}

void check_fit_to_one_size()
{ 
    struct matrix_t matr_first;
    matr_first.matr = NULL; matr_first.row = 4; matr_first.col = 4;
    struct matrix_t matr_second;
    matr_second.matr = NULL; matr_second.row = 3; matr_second.col = 3;    
    create_matrix(&matr_first);
    create_matrix(&matr_second);
    fill_matrix(&matr_first); 
    fill_matrix(&matr_second);
    int err = 0;
    int size = fit_to_one_size(&matr_first, &matr_second, &err);
    if (matr_first.matr && matr_second.matr && size == 4)
        printf("Correct fit first\n");
    matr_second.row = 4; matr_second.col = 4;
    delete_matrix(&matr_first);
    delete_matrix(&matr_second);

    struct matrix_t matr_third;
    matr_third.matr = NULL; matr_third.row = 3; matr_third.col = 3;
    struct matrix_t matr_fourth;
    matr_fourth.matr = NULL; matr_fourth.row = 4; matr_fourth.col = 4;    
    create_matrix(&matr_third);
    create_matrix(&matr_fourth);
    fill_matrix(&matr_third); 
    fill_matrix(&matr_fourth);
    err = 0;
    size = fit_to_one_size(&matr_third, &matr_fourth, &err);
    if (matr_third.matr && matr_fourth.matr && size == 4)
        printf("Correct fit first\n");
    matr_third.row = 4; matr_third.col = 4;
    delete_matrix(&matr_third);
    delete_matrix(&matr_fourth);
}
