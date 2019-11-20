#include "head.h"

void withodut_too_young_girls(struct child **children, int *count)
{
    convert_sex_in_int(*children, *count);
    find_and_shift_girls_to_end(children, count);
    *children = realloc(*children, *count * sizeof(struct child));
}

void find_and_shift_girls_to_end(struct child **children, int *count)
{
    for (int i = 0; i < *count; i++)
    {
        if ((*children)[i].sex_key == 1 && (*children)[i].cur_child.age > 17)
        {
            printf("YES");
            shift_to_end(children, *count, i);
            *count -= 1;
            i--;
        }
    }
}

void shift_to_end(struct child **children, int count, int need_position)
{
    free_field((&(*children)[need_position]));
    printf("pos %d\n", need_position);
    for (int i = need_position; i < count - 1; i++)
        (*children)[i] = (*children)[i + 1]; 
}
