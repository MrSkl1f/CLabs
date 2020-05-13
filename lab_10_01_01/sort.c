#include "head.h"

void sort_struct_with_key(struct child *children, int count, int *err)
{   
    char *check = malloc(256 * sizeof(char));
    printf("Input key > ");
    if (scanf("%s", check) == 1)
    {
        if (!strcmp(check, SORTSURNAME))
            sort_table_insertion(children, count, cmp_first_name);
        else if (!strcmp(check, SORTSEX))
        {
            convert_sex_in_int(children, count);
            sort_table_insertion(children, count, cmp_sex);
        }
        else if (!strcmp(check, SORTBIRTHDATE))
            sort_table_insertion(children, count, cmp_birthday);
        else if (!strcmp(check, SORTGRADE))
        {
            find_average(children, count);
            sort_table_insertion(children, count, cmp_grade);
        }
        else
            *err = ERROR;
    } 
    else
        *err = ERROR;
    free(check);
}

void convert_sex_in_int(struct child *children, int count)
{
    for (int i = 0; i < count; i++)
    {
        children[i].sex_key = 0;
        if (create_new_low_word(children[i].sex, "male"))
            children[i].sex_key = 1;
    }
}

int cmp_birthday(struct child *first, struct child *second)
{
    return (strcmp(first->birthday, second->birthday) > 0);
}

int cmp_first_name(struct child *first, struct child *second)
{
    return (strcmp(first->first_name, second->first_name) > 0);
}

int cmp_sex(struct child *first, struct child *second)
{
    return (strcmp(first->sex, second->sex) > 0);
}

int cmp_grade(struct child *first, struct child *second)
{
    return first->cur_mark.average > second->cur_mark.average;
}

void sort_table_insertion(struct child *children, int count, int (*operations)(struct child *, struct child *))
{
    int location;
    struct child cur_table;
    
    for (int i = 1; i < count; i++)
    {
        cur_table = children[i];
        location = i - 1;
        while (location >= 0 && operations(&(children[location]), &cur_table))
        {
            children[location + 1] = children[location];
            location = location - 1;
        }
        children[location + 1] = cur_table;
    }
}



