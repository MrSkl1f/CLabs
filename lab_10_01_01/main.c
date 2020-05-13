#include "head.h"

int main()
{
    int err = OK;
    struct child *children = NULL;
    int count = 0;
    input_children(&children, &err, &count);
    if (err == OK && count > 0)
    {
        convert_age(children, count);
        withodut_too_young_girls(&children, &count);
        //see_out_structure(children, count);
        if (count > 0)
        {
            add_mark(children, count);
            sort_struct_with_key(children, count, &err);
            if (err == OK)
            {
                see_out_structure(children, count);
                output_in_file(children, count);
            }
        }   
        else
            err = ERROR;
    }
    printf("COUNT - %d", count);
    delete_structure(&children, count);
    return err;
}
