#include "main.h"

void input_key_for_task(struct list **cur_list, int *err)
{
    char *check = malloc(50 * sizeof(char));
    if (scanf("%s", check) == 1)
    {
        if (strcmp(check, FIRST_TASK) == 0)
            implementation_first(cur_list, err);
        else if (strcmp(check, SECOND_TASK) == 0)
            implementation_second(cur_list, err);
        else if (strcmp(check, THIRD_TASK) == 0)
            implementation_third(cur_list, err);
        else if (strcmp(check, FOURTH_TASK) == 0)
            implementation_fourth(cur_list, err);
        else
            *err = 1;
    }
    else
        *err = 1;
    free(check);
}

void data_input(struct list **cur_list, int *err, int *size_list)
{
    char *line = malloc(50 * sizeof(char));
    int cur_check = 1;
    int cur_num, cur_deg;
    while (cur_check && !(*err))
    {
        if (scanf("%d", &cur_num) == 1 && scanf("%d", &cur_deg) == 1)
        {
            if (*size_list > 0)
            {
                if (cur_deg < *(int *)((*cur_list)->info.degree))
                    push_list(cur_list, cur_num, cur_deg);
                else
                    *err = 1;
            }
            else
                push_list(cur_list, cur_num, cur_deg);

            if (cur_deg == 0)
                cur_check = 0;
            
            if (!(*err))
                (*size_list)++;
        }
        else
            *err = 1;
    }
    free(line);
}

int check_previous(struct list *cur_list, int deg)
{
    int err = 1;
    if (*(int *)(cur_list->info.degree) < deg)
        err = 0;
    return err;
}