#include "base.h"

int main()
{
    int err = OK;
    struct matrix_t matr_first, matr_second;
    matr_first.matr = NULL;
    matr_second.matr = NULL;

    // Create first matr
    matr_first.row = 0, matr_first.col = 0;

    matrix_calculation(&matr_first, &err);
    if (!err)
    {     
        int s;
        s = transformation(&matr_first);  
        matr_first.row = s; matr_first.col = s;
        if (matr_first.matr)
        {
            matr_second.row = 0, matr_second.col = 0;
            matrix_calculation(&matr_second, &err);
            if (!err)
            {
                int k = transformation(&matr_second);
                matr_second.row = k; matr_second.col = k;
                if (matr_second.matr)
                {
                    int size = fit_to_one_size(&matr_first, &matr_second, &err);
                    if (!err)
                    {
                        matr_first.row = size; matr_first.col = size;
                        matr_second.row = size; matr_second.col = size;
                        struct matrix_t res; 
                        res.matr = NULL; res.row = size; res.col = size;
                        create_matrix(&res);
                        if (res.matr)
                        {
                            multiplication(&res, matr_first, matr_second, size, &err);
                            if (!err)
                                see_out_matrix(res);  
                            delete_matrix(&res);
                        }
                        else
                            err = ERROR;
                        delete_matrix(&matr_first);
                        delete_matrix(&matr_second);
                    }
                    else if (err == FIRST)
                        delete_matrix(&matr_first);
                    else if (err == SECOND)
                        delete_matrix(&matr_second);
                }
                else
                {
                    err = ERROR;
                    delete_matrix(&matr_first);
                }
            }
            else
                delete_matrix(&matr_first);         
        }
        else
            err = ERROR;
    }  
    return err;
}

