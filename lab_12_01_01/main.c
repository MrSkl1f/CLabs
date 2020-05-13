#include "main.h"

int main()
{
    int err = 0;
    struct list *cur_list = NULL;
    input_key_for_task(&cur_list, &err);
    free_list(&cur_list);
    return err;
}

